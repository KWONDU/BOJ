#include <iostream>

using namespace std;

const int mod = 1e9;

int N, dp[100 + 1][10];

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    dp[1][0] = 0;
    for (int i = 1; i < 10; i++) dp[1][i] = 1;
    for (int i = 2; i <= N; i++) {
        dp[i][0] = dp[i - 1][1] % mod;
        for (int j = 1; j <= 8; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;
        }
        dp[i][9] = dp[i - 1][8] % mod;
    }

    long long int sum = 0;
    for (int i = 0; i < 10; i++) sum += dp[N][i];
    cout << (sum % mod);

    return 0;
}