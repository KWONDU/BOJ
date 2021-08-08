#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    int score[300 + 1];
    for (int i = 1; i <= n; i++)
        cin >> score[i];
    
    int dp[300 + 1];
    dp[0] = 0;
    dp[1] = score[1];
    if (n > 1) {
        dp[2] = score[1] + score[2];
        for (int i = 3; i <= n; i++)
            dp[i] = max(dp[i - 2], dp[i - 3] + score[i - 1]) + score[i];
    }
    
    cout << dp[n];
}