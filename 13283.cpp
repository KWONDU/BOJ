#include <iostream>
#include <memory.h>

using namespace std;

int n, w[300 + 1], dp[300 + 1][300 + 1];

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (true) {
        cin >> n;
        if (n == 0) break;
        for (int i = 1; i <= n; i++) cin >> w[i];
        
        for (int i = 0; i < 300 + 1; i++) memset(dp[i], 0, sizeof(dp[i]));
        
        int j;
        for (int len = 0; len < n; len++) {
            for (int i = 1; i <= n - len; i++) {
                j = i + len;
                if (dp[i + 1][j - 1] == ((j - 1) - (i + 1) + 1) && abs(w[i] - w[j]) < 2) {
                    dp[i][j] = j - i + 1;
                } else {
                    for (int k = i; k < j; k++) {
                        dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
                    }
                }
            }
        }
        
        cout << dp[1][n] << "\n";
    }
    
    return 0;
}