#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    const int mod = 1000000007;
    
    int n;
    cin >> n;
    
    long long int dp[1515][3];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            dp[i][j] = 0;
    dp[0][0] = 0; dp[0][1] = 0; dp[0][2] = 0;
    if (n > 1) {
        dp[1][0] = 0; dp[1][1] = 1; dp[1][2] = 1;
    }
    for (int i = 2; i < n; i++) {
        dp[i][0] += (dp[i - 1][2] + dp[i - 1][1]) % mod;
        dp[i][0] %= mod;
        dp[i][1] += (dp[i - 1][0] + dp[i - 1][2]) % mod;
        dp[i][1] %= mod;
        dp[i][2] += (dp[i - 1][1] + dp[i - 1][0]) % mod;
        dp[i][2] %= mod;
    }
    
    cout << dp[n - 1][1];
}