#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

const int mod = 1e9;
const int MAX = 100;

int n;
int dp[MAX + 1][10][1<<10];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    
    int full = (1<<10) - 1;
    for (int i = 1; i <= MAX; i++)
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k <= full; k++) dp[i][j][k] = 0;
    
    for (int j = 1; j <= 9; j++)
        dp[1][j][1<<j] = 1;
    
    for (int i = 2; i <= n; i++)
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k <= full; k++) {
                if (0 < j)
                    dp[i][j][k | 1<<j] += dp[i - 1][j - 1][k];
                dp[i][j][k | 1<<j] %= mod;
                if (j < 9)
                    dp[i][j][k | 1<<j] += dp[i - 1][j + 1][k];
                dp[i][j][k | 1<<j] %= mod;
            }
    
    int ans = 0;
    for (int j = 0; j <= 9; j++) {
        ans += dp[n][j][full];
        ans %= mod;
    } cout << ans;
    
    return 0;
}