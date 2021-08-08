#include <iostream>
#include <memory.h>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 500000 + 1;

struct Triple {
    int first, second, third;
    Triple (int f, int s, int t) {
        first = f;
        second = s;
        third = t;
    }
};

int N, score[500000][3], temp;
vector<Triple> v;

int seg[1<<20];

void update (int node, int left, int right, int updateIdx, int val) {
    if (updateIdx < left || right < updateIdx) return ;
    else if (left == updateIdx && updateIdx == right) {
        seg[node] = val;
        return ;
    }
    
    int mid = (left + right) / 2;
    update(node * 2, left, mid, updateIdx, val);
    update(node * 2 + 1, mid + 1, right, updateIdx, val);
    seg[node] = min(seg[node * 2], seg[node * 2 + 1]);
    
    return ;
}

int query (int node, int left, int right, int queryLeft, int queryRight) {
    if (queryRight < left || right < queryLeft) return INF;
    else if (queryLeft <= left && right <= queryRight) return seg[node];
    
    int mid = (left + right) / 2;
    return min(query(node * 2, left, mid, queryLeft, queryRight), query(node * 2 + 1, mid + 1, right, queryLeft, queryRight));
}

bool comp (Triple t1, Triple t2) {
    return t1.first < t2.first;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 0; i < 1<<20; i++) seg[i] = INF;
    
    cin >> N;
    for (int j = 0; j < 3; j++)
        for (int i = 0; i < N; i++) {
            cin >> temp;
            score[temp - 1][j] = i + 1;
        }
    
    for (int i = 0; i < N; i++) v.push_back(Triple(score[i][0], score[i][1], score[i][2]));
    
    sort(v.begin(), v.end(), comp);
    
    int cnt = 0, j = 0;
    for (auto x : v) {
        if (query(1, 1, N, 1, x.second - 1) > x.third) cnt++;
        update(1, 1, N, x.second, x.third);
    }
    
    cout << cnt;
    
    return 0;
}