#include <iostream>

using namespace std;

int N, w[200000 + 1], p[200000 + 1];

int seg[1<<19];

void update (int node, int left, int right, int updateIdx, int val) {
    if (updateIdx < left || right < updateIdx) return ;
    else if (updateIdx == left && right == updateIdx) {
        seg[node] = val;
        return ;
    }
    
    int mid = (left + right) / 2;
    update(node * 2, left, mid, updateIdx, val);
    update(node * 2 + 1, mid + 1, right, updateIdx, val);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
    
    return ;
}

int findQuery (int node, int left, int right, int sum) {
    if (left == right) return left;
    
    int mid = (left + right) / 2;
    if (seg[node * 2] >= sum) return findQuery(node * 2, left, mid, sum);
    else return findQuery(node * 2 + 1, mid + 1, right, sum - seg[node * 2]);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for (int i = 1; i <= 1<<19; i++) seg[i] = 0;
    
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> w[i];
    for (int i = 1; i <= N; i++) cin >> p[i];
    
    for (int i = 1; i <= N; i++) update(1, 1, N, i, w[i]);
    for (int i = 1; i <= N; i++) {
        int x = findQuery(1, 1, N, p[i]);
        cout << x << " ";
        update(1, 1, N, x, 0);
    }
    
    return 0;
}