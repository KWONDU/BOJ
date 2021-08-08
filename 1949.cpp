#include <iostream>
#include <vector>

using namespace std;

int N;
int citizen[10000 + 1];
vector<int> adj[10000 + 1];

int dp[10000 + 1][2];

int max (int n1, int n2) {
    return n1 > n2 ? n1 : n2;
}

int cal (int cur, int par, int chk) {
    if (dp[cur][chk] != -1) return dp[cur][chk];
    
    int ret = 0;
    if (chk) {
        ret = citizen[cur];
        for (int child: adj[cur]) {
            if (child == par) continue;
            ret += cal(child, cur, 0);
        }
    } else {
        for (int child: adj[cur]) {
            if (child == par) continue;
            ret += max(cal(child, cur, 0), cal(child, cur, 1));
        }
    }
    
    return dp[cur][chk] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> citizen[i];
    for (int i = 1; i <= N - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for (int i = 1; i <= 10000; i++)
        for (int j = 0; j < 2; j++) dp[i][j] = -1;
    
    cout << max(cal(1, -1, 0), cal(1, -1, 1));
    
    return  0;
}