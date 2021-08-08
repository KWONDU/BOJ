#include <iostream>

using namespace std;

int N, M, A, chk;

int seg[1<<21];

void update (int node, int left, int right, int updateIdx, int val) {
    if (updateIdx < left || right < updateIdx) return ;
    else if (updateIdx == left && right == updateIdx) {
        seg[node] = val % 2;
        return ;
    }
    
    int mid = (left + right) / 2;
    update(node * 2, left, mid, updateIdx, val);
    update(node * 2 + 1, mid + 1, right, updateIdx, val);
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
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A;
        update(1, 1, N, i, A);
    }
    cin >> M;
    while (M--) {
        cin >> chk;
        int i, x, l, r;
        switch (chk) {
            case 1 :
                cin >> i >> x;
                update(1, 1, N, i, x);
                break;
            case 2 :
                cin >> l >> r;
                cout << (r - l + 1) - query(1, 1, N, l, r) << "\n";
                break;
            case 3 :
                cin >> l >> r;
                cout << query(1, 1, N, l, r) << "\n";
        }
    }
    
    return 0;
}