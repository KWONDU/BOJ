#include <iostream>

using namespace std;

const int INF = 1e9 + 1;

int N, M, A[100000 + 1], chk;

int seg[1<<21];

void update (int node, int left, int right, int updateIdx, int val) {
    if (updateIdx < left || right < updateIdx) return ;
    else if (updateIdx == left && right == updateIdx) {
        seg[node] = updateIdx;
        return ;
    }
    
    int mid = (left + right) / 2;
    update(node * 2, left, mid, updateIdx, val);
    update(node * 2 + 1, mid + 1, right, updateIdx, val);
    if (A[seg[node * 2]] <= A[seg[node * 2 + 1]]) seg[node] = seg[node * 2];
    else seg[node] = seg[node * 2 + 1];
    return ;
}

int query (int node, int left, int right, int queryLeft, int queryRight) {
    if (queryRight < left || right < queryLeft) return 0;
    else if (queryLeft <= left && right <= queryRight) return seg[node];
    
    int mid = (left + right) / 2;
    int minLeftPos = query(node * 2, left, mid, queryLeft, queryRight);
    int minRightPos = query(node * 2 + 1, mid + 1, right, queryLeft, queryRight);
    if (A[minLeftPos] <= A[minRightPos]) return minLeftPos;
    else return minRightPos;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    A[0] = INF;
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        update(1, 1, N, i, A[i]);
    }
    cin >> M;
    while (M--) {
        cin >> chk;
        int i, j, v;
        switch (chk) {
            case 1 :
                cin >> i >> v;
                A[i] = v;
                update(1, 1, N, i, v);
                break;
            case 2 :
                cin >> i >> j;
                cout << query(1, 1, N, i, j) << "\n";
        }
    }
    
    return 0;
}