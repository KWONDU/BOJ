#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max (int n1, int n2) {
    return n1 > n2 ? n1 : n2;
}

int n;
int w[10000 + 1];
vector<int> tree[10000 + 1];

int dp[10000 + 1][2];
vector<int> ans;

int cal (int cur, int par, int chk) {
    if (dp[cur][chk] != -1) return dp[cur][chk];
    
    int sum = 0;
    if (chk == 1) {
        sum += w[cur];
        for (int child: tree[cur]) {
            if (child == par) continue;
            sum += cal(child, cur, 0);
        }
    } else {
        for (int child: tree[cur]) {
            if (child == par) continue;
            sum += max(cal(child, cur, 0), cal(child, cur, 1));
        }
    }
    return dp[cur][chk] = sum;
}

void backTracking (int cur, int par, int chk) {
    if (chk == 1) {
        ans.push_back(cur);
        for (int child: tree[cur]) {
            if (child == par) continue;
            backTracking(child, cur, 0);
        }
    } else {
        for (int child: tree[cur]) {
            if (child == par) continue;
            if (dp[child][0] > dp[child][1]) backTracking(child, cur, 0);
            else backTracking(child, cur, 1);
        }
    }
    
    return;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 2; j++) dp[i][j] = -1;
    
    cout << max(cal(1, 0, 0), cal(1, 0, 1)) << "\n";
    
    if (dp[1][0] > dp[1][1]) backTracking(1, 0, 0);
    else backTracking(1, 0, 1);
    
    sort(ans.begin(), ans.end());
    for (int i: ans) cout << i << " ";
    
    return 0;
}