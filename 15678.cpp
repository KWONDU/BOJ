#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>

using namespace std;

int n, d;
long long int* k;
long long int* dp;

long long int max__ (long long int a, long long int b) {
    if (a > b) return a;
    else return b;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> d;
    k = new long long int[n];
    for (int i = 0; i < n; i++) cin >> k[i];
    
    deque< pair<long long int, int> > dq;
    
    dp = new long long int[n];
    for (int i = 0; i < n; i++) {
        dp[i] = k[i];
        if (!dq.empty() && dq.front().second < i - d)
            dq.pop_front();
        if (!dq.empty())
            dp[i] = max__(dp[i], dq.front().first + k[i]);
        while (!dq.empty() && dq.back().first < dp[i])
            dq.pop_back();
        dq.push_back(make_pair(dp[i], i));
    }
    
    long long int ans = dp[0];
    for (int i = 1; i < n; i++)
        if (ans < dp[i]) ans = dp[i];
    cout << ans;
    
    return 0;
}