#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
#define MAX 1000

int card[MAX + 1];
int dp[MAX + 1][MAX + 1];

int func (int left, int right, bool chk) {
    if (left > right) return 0;
    if (dp[left][right] != -1) return dp[left][right];
    if (chk)
        return dp[left][right] = max(func(left + 1, right, !chk) + card[left], func(left, right - 1, !chk) + card[right]);
    else
        return dp[left][right] = min(func(left + 1, right, !chk), func(left, right - 1, !chk));
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) cin >> card[i];
        
        for (int i = 1; i <= MAX; i++)
            for (int j = 1; j <= MAX; j++) dp[i][j] = -1;
        cout << func(1, n, true) << "\n";
    }
    
    return 0;
}