#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    const int INF = 10000;
    
    int n, m;
    cin >> n >> m;
    
    char map[100][100];
    for (int i = 0; i < n; i++) cin >> map[i];
    
    int dp[100][100];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) dp[i][j] = INF;
    
    dp[0][0] = 1;
    
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        
        if (p.first != 0 && map[p.first - 1][p.second] == '1')
            if (dp[p.first - 1][p.second] > dp[p.first][p.second] + 1) {
                dp[p.first - 1][p.second] = dp[p.first][p.second] + 1;
                q.push(make_pair(p.first - 1, p.second));
            }
        if (p.first != n - 1 && map[p.first + 1][p.second] == '1')
            if (dp[p.first + 1][p.second] > dp[p.first][p.second] + 1) {
                dp[p.first + 1][p.second] = dp[p.first][p.second] + 1;
                q.push(make_pair(p.first + 1, p.second));
            }
        if (p.second != 0 && map[p.first][p.second - 1] == '1')
            if (dp[p.first][p.second - 1] > dp[p.first][p.second] + 1) {
                dp[p.first][p.second - 1] = dp[p.first][p.second] + 1;
                q.push(make_pair(p.first, p.second - 1));
            }
        if (p.second != m - 1 && map[p.first][p.second + 1] == '1')
            if (dp[p.first][p.second + 1] > dp[p.first][p.second] + 1) {
                dp[p.first][p.second + 1] = dp[p.first][p.second] + 1;
                q.push(make_pair(p.first, p.second + 1));
            }
    }
    
    cout << dp[n - 1][m - 1];
    
    
    return 0;
}