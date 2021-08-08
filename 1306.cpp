#include <iostream>

using namespace std;

int N, M, cd;

int seg[1<<21];

void update (int node, int left, int right, int updateIdx, int val) {
    if (updateIdx < left || right < updateIdx) return ;
    else if (updateIdx == left && right == updateIdx) {
        seg[node] = val;
        return ;
    }
    
    int mid = (left + right) / 2;
    update(node * 2, left, mid, updateIdx, val);
    update(node * 2 + 1, mid + 1, right, updateIdx, val);
    seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
    return ;
}

int query (int node, int left, int right, int queryLeft, int queryRight) {
    if (queryRight < left || right < queryLeft) return 0;
    else if (queryLeft <= left && right <= queryRight) return seg[node];
    
    int mid = (left + right) / 2;
    return max(query(node * 2, left, mid, queryLeft, queryRight), query(node * 2 + 1, mid + 1, right, queryLeft, queryRight));
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> cd;
        update(1, 1, N, i, cd);
    }
    
    for (int pos = M; pos <= N - M + 1; pos++)
        cout << query(1, 1, N, pos - (M - 1), pos + (M - 1)) << " ";
    
    return 0;
}