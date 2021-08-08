#include <iostream>

using namespace std;

int n, m, super[100000 + 1], chk;

int seg[1<<21];

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

int query (int node, int left, int right, int queryPos) {
    if (queryPos < left || right < queryPos) return 0;
    else if (queryPos == left && right == queryPos) return seg[node];
    
    int mid = (left + right) / 2;
    if (queryPos <= mid) return query(node * 2, left, mid, queryPos);
    else return query(node * 2 + 1, mid + 1, right, queryPos);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for (int i = 0; i < 1<<21; i++) seg[i] = 0;
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> super[i];
    
    while (m--) {
        cin >> chk;
        int i, w;
        switch (chk) {
            case 1 :
                cin >> i >> w;
                while (i != -1) {
                    update(1, 1, n, i, w);
                    i = super[i];
                }
                break;
            case 2 :
                cin >> i;
                cout << query(1, 1, n, i) << "\n";
                break;
        }
    }
    
    return 0;
}