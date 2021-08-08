#include <iostream>

using namespace std;

int N, Is[100000 + 1], ans[100000 + 1];

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
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
    return ;
}

int query (int node, int left, int right, int sum) {
    if (left == right) return left;
    
    int mid = (left + right) / 2;
    if (sum <= seg[node * 2]) return query(node * 2, left, mid, sum);
    else return query(node * 2 + 1, mid + 1, right, sum - seg[node * 2]);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for (int i = 0; i < 1<<21; i++) seg[i] = 0;
    
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> Is[i];
    
    for (int i = 1; i <= N; i++) update(1, 1, N, i, 1);
    
    for (int i = N; i >= 1; i--) {
        int pos = query(1, 1, N, i - Is[i]);
        ans[pos] = i;
        update(1, 1, N, pos, 0);
    }
    
    for (int i = 1; i <= N; i++) cout << ans[i] << " ";
    
    return 0;
}