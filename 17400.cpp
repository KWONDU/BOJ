#include <iostream>

using namespace std;

int N, Q, c, chk, L, R, x;

long long int seg[1<<20];

long long int ABS (long long int ll) {
    return ll >= 0 ? ll : -ll;
}

void update (int node, int left, int right, int updateIdx, int val) {
    if (updateIdx < left || right < updateIdx) return ;
    else if (updateIdx == left && right == updateIdx) {
        if (updateIdx % 2 == 0) seg[node] += val;
        else seg[node] -= val;
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
    
    for (int i = 0; i < 1<<20; i++) seg[i] = 0;
    
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> c;
        update(1, 1, N, i, c);
    }
    while (Q--) {
        cin >> chk;
        switch (chk) {
            case 1 :
                cin >> L >> R;
                cout << ABS(query(1, 1, N, L, R)) << "\n";
                break;
            case 2 :
                cin >> L >> x;
                update(1, 1, N, L, x);
                break;
        }
    }
    
    return 0;
}