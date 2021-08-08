#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, runSkill[500000 + 1];
vector<pair<int, int>> v;

int seg[1<<20];

bool comp (pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second ? true : false;
}

void update (int node, int left, int right, int updateIdx) {
    if (updateIdx < left || right < updateIdx) return ;
    else if (left == updateIdx && updateIdx == right) {
        seg[node]++;
        return ;
    }
    
    int mid = (left + right) / 2;
    update(node * 2, left, mid, updateIdx);
    update(node * 2 + 1, mid + 1, right, updateIdx);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
    return ;
}

int query (int node, int left, int right, int queryLeft, int queryRight) {
    if (queryRight < left || right < queryLeft) return 0;
    else if (queryLeft <= left && right <= queryRight) return seg[node];
    
    int mid = (left + right) / 2;
    return query(node * 2, left, mid, queryLeft, queryRight) + query(node * 2 + 1, mid + 1, right, queryLeft, queryRight);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for (int i = 0; i < 1<<20; i++) seg[i] = 0;
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> runSkill[i];
        v.push_back(make_pair(runSkill[i], i));
    }
    
    sort(v.begin(), v.end());
    for (int i = 0; i < N; i++) v[i].first = (i + 1);
    sort(v.begin(), v.end(), comp);
    
    int pos;
    for (int i = 0; i < N; i++) {
        pos = v[i].first;
        
        cout << (i + 1 - query(1, 1, N, 1, pos - 1)) << "\n";
        
        update(1, 1, N, pos);
    }
    
    return 0;
}