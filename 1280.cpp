#include <iostream>

using namespace std;

const long long int mod = 1e9 + 7;
const int MAX = 2e5;

int N, X[MAX + 1];

long long int seg[1<<19];
long long int seg2[1<<19];

void update (int node, int left, int right, int updateIdx) {
    if (updateIdx < left || right < updateIdx) return ;
    else if (updateIdx == left && right == updateIdx) {
        seg[node] = (seg[node] + updateIdx) % mod;
        return ;
    }
    
    int mid = (left + right) / 2;
    update(node * 2, left, mid, updateIdx);
    update(node * 2 + 1, mid + 1, right, updateIdx);
    seg[node] = (seg[node * 2] + seg[node * 2 + 1]) % mod;
    return ;
}

long long int query (int node, int left, int right, int queryLeft, int queryRight) {
    if (queryRight < left || right < queryLeft) return 0;
    else if (queryLeft <= left && right <= queryRight) return seg[node];
    
    int mid = (left + right) / 2;
    return (query(node * 2, left, mid, queryLeft, queryRight) + query(node * 2 + 1, mid + 1, right, queryLeft, queryRight)) % mod;
}

void update2 (int node, int left, int right, int updateIdx) {
    if (updateIdx < left || right < updateIdx) return ;
    else if (updateIdx == left && right == updateIdx) {
        seg2[node]++;
        return ;
    }
    
    int mid = (left + right) / 2;
    update2(node * 2, left, mid, updateIdx);
    update2(node * 2 + 1, mid + 1, right, updateIdx);
    seg2[node] = seg2[node * 2] + seg2[node * 2 + 1];
    return ;
}

long long int query2 (int node, int left, int right, int queryLeft, int queryRight) {
    if (queryRight < left || right < queryLeft) return 0;
    else if (queryLeft <= left && right <= queryRight) return seg2[node];
    
    int mid = (left + right) / 2;
    return query2(node * 2, left, mid, queryLeft, queryRight) + query2(node * 2 + 1, mid + 1, right, queryLeft, queryRight);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for (int i = 0; i < 1<<19; i++) seg[i] = 0;
    for (int i = 0; i < 1<<19; i++) seg2[i] = 0;
    
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> X[i];
    
    update(1, 0, MAX - 1, X[1]);
    update2(1, 0, MAX - 1, X[1]);
    
    long long int leftD, rightD, ans = 1, leftMul, rightMul;
    long long int leftCnt, rightCnt;
    for (int i = 2; i <= N; i++) {
        leftD = query(1, 0, MAX - 1, 0, X[i] - 1);
        rightD = query(1, 0, MAX - 1, X[i] + 1, MAX - 1);
        leftCnt = query2(1, 0, MAX - 1, 0, X[i] - 1);
        rightCnt = query2(1, 0, MAX - 1, X[i] + 1, MAX - 1);
        
        leftMul = ((leftCnt * (long long int)X[i]) % mod - leftD) % mod;
        rightMul = (rightD - ((rightCnt * (long long int)X[i]) % mod)) % mod;
        
        ans = (ans * ((leftMul + rightMul) % mod)) % mod;
        
        update(1, 0, MAX - 1, X[i]);
        update2(1, 0, MAX - 1, X[i]);
    }
    
    cout << (ans + mod) % mod;
    
    return 0;
}