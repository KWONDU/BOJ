#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    int w[100 + 1], v[100 + 1];
    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];
    
    int dp[100 + 1][100000 + 1];
    for (int j = 0; j <= k; j++)
        dp[0][j] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= k; j++) {
            if (j >= w[i])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    cout << dp[n][k];
}