#include <iostream>

using namespace std;

const int mod = 1000000007;

int N, M, K, a, b, c, d;

long long int seg[1<<21];

void update (int node, int left, int right, int updateIdx, int val) {
    if (updateIdx < left || right < updateIdx) return ;
    else if (updateIdx == left && right == updateIdx) {
        seg[node] = val;
        return ;
    }
    
    int mid = (left + right) / 2;
    update(node * 2, left, mid, updateIdx, val);
    update(node * 2 + 1, mid + 1, right, updateIdx, val);
    seg[node] = (seg[node * 2] * seg[node * 2 + 1]) % mod;
    return ;
}

long long int query (int node, int left, int right, int queryLeft, int queryRight) {
    if (queryRight < left || right < queryLeft) return 1;
    else if (queryLeft <= left && right <= queryRight) return seg[node];
    
    int mid = (left + right) / 2;
    return (query(node * 2, left, mid, queryLeft, queryRight) * query(node * 2 + 1, mid + 1, right, queryLeft, queryRight)) % mod;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for (int i = 0; i < 1<<21; i++) seg[i] = 0;
    
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        cin >> d;
        update(1, 1, N, i, d);
    }
    for (int i = 1; i <= M + K; i++) {
        cin >> a;
        switch(a) {
            case 1 :
                cin >> b >> c;
                update(1, 1, N, b, c);
                break;
            case 2 :
                cin >> b >> c;
                cout << query(1, 1, N, b, c) << "\n";
                break;
        }
    }
    
    return 0;
}