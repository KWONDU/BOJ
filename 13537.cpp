#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, A;

vector<int> seg[1<<18];

int cnt (int node, int queryPos) {
    int up = upper_bound(seg[node].begin(), seg[node].end(), queryPos) - seg[node].begin();
    return (seg[node].size() - 1) - up + 1;
}

void update (int node, int left, int right, int updateIdx, int val) {
    if (updateIdx < left || right < updateIdx) return ;
    
    seg[node].push_back(val);
    
    if (updateIdx == left && right == updateIdx) return ;
    
    int mid = (left + right) / 2;
    update(node * 2, left, mid, updateIdx, val);
    update(node * 2 + 1, mid + 1, right, updateIdx, val);
    return ;
}

int query (int node, int left, int right, int queryLeft, int queryRight, int queryPos) {
    if (queryRight < left || right < queryLeft) return 0;
    else if (queryLeft <= left && right <= queryRight) return cnt(node, queryPos);
    
    int mid = (left + right) / 2;
    return query(node * 2, left, mid, queryLeft, queryRight, queryPos) + query(node * 2 + 1, mid + 1, right, queryLeft, queryRight, queryPos);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A;
        update(1, 1, N, i, A);
    }
    
    for (int i = 0; i < 1<<18; i++) sort(seg[i].begin(), seg[i].end());
    
    cin >> M;
    while (M--) {
        int i, j, k;
        cin >> i >> j >> k;
        cout << query(1, 1, N, i, j, k) << "\n";
    }
    
    return 0;
}