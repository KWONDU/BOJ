#include <iostream>
#include <memory.h>

using namespace std;

int n, dp[500 + 1][500 + 1 + 1];

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 0; i <= 500; i++) memset(dp[i], 0, sizeof(dp[i]));

    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> dp[i][j];
            dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
        }
    }

    int maxVal = dp[n][0];
    for (int i = 1; i <= n; i++) maxVal = max(maxVal, dp[n][i]);
    cout << maxVal;

    return 0;
}