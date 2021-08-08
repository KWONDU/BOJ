#include <iostream>

using namespace std;

int N, Q, chk, p, q, x;
long long int seg[1<<21];

void update (int node, int left, int right, int updateIdx, int val) {
    if (updateIdx < left || right < updateIdx) return ;
    else if (updateIdx == left && right == updateIdx) {
        seg[node] += val;
        return ;
    }
    
    int mid = (left + right) / 2;
    update(node * 2, left, mid, updateIdx, val);
    update(node * 2 + 1, mid + 1, right, updateIdx, val);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
    return ;
}

long long int query (int node, int left, int right, int queryLeft, int queryRight) {
    if (queryRight < left || right < queryLeft) return 0;
    else if (queryLeft <= left && right <= queryRight) return seg[node];
    
    int mid = (left + right) / 2;
    return query(node * 2, left, mid, queryLeft, queryRight) + query(node * 2 + 1, mid + 1, right, queryLeft, queryRight);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> Q;
    while (Q--) {
        cin >> chk;
        switch (chk) {
            case 1 :
                cin >> p >> x;
                update(1, 1, N, p, x);
                break;
            case 2 :
                cin >> p >> q;
                cout << query(1, 1, N, p, q) << "\n";
                break;
        }
    }
    
    return 0;
}