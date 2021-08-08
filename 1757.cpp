#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int max (int n1, int n2) {
    if (n1 > n2)
        return n1;
    else
        return n2;
}

int max (int n1, int n2, int n3) {
    return max(max(n1, n2), n3);
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    int* d = new int[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> d[i];
    
    int dp[10000 + 1 + 1][500 + 1 + 1][2];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (j == 0)
                dp[i][j][0] = max(dp[i - 1][j + 1][0], dp[i - 1][j + 1][1], dp[i - 1][j][0]);
            else if (j == 1) {
                dp[i][j][0] = max(dp[i - 1][j + 1][0], dp[i - 1][j + 1][1]);
                dp[i][j][1] = max(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1]) + d[i];
            }
            else {
                dp[i][j][0] = max(dp[i - 1][j + 1][0], dp[i - 1][j + 1][1]);
                dp[i][j][1] = dp[i - 1][j - 1][1] + d[i];
            }
        }
    }
    cout << dp[n][0][0];
}