#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int t;
    cin >> t;
    long long int dp[100 + 1];
    dp[1] = 1; dp[2] = 1; dp[3] = 1;
    int n;
    for (int i = 0; i < t; i++) {
        cin >> n;
        for (int j = 4; j <= n; j++)
                dp[j] = dp[j - 2] + dp[j - 3];
        cout << dp[n] << "\n";
    }
}