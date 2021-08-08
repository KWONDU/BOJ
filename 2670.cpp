#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

double max (double d1, double d2) {
    if (d1 > d2)
        return d1;
    else
        return d2;
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    double num[10000 + 1];
    for (int i = 1; i <= n; i++)
        cin >> num[i];
    
    double dp[10000 + 1];
    dp[0] = 1;
    double maxdp = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = max(dp[i - 1] * num[i], num[i]);
        if (dp[i] > maxdp)
            maxdp = dp[i];
    }
    
    cout << fixed;
    cout.precision(3);
    cout << maxdp;
}