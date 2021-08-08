#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    const int mod = 1000000007;
    
    int n, m;
    cin >> n >> m;
    
    int dp[1000 + 1][1000 + 1];
    for (int i = 1; i <= n; i++)
        dp[i][1] = 1;
    for (int j = 1; j <= m; j++)
        dp[1][j] = 1;
    
    for (int i = 2; i <= n; i++)
        for (int j = 2; j <= m; j++)
            dp[i][j] = ((dp[i][j - 1] + dp[i - 1][j - 1]) % mod + dp[i - 1][j]) % mod;
    
    cout << dp[n][m];
}