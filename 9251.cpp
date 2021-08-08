#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    string s1, s2;
    cin >> s1 >> s2;
    s1.insert(0, "0"); s2.insert(0, "0");
    
    int dp[1000 + 1][1000 + 1];
    for (int i = 0; i < s1.length(); i++)
        for (int j = 0; j < s2.length(); j++)
            dp[i][j] = 0;
    
    for (int i = 1; i < s1.length(); i++)
        for (int j = 1; j < s2.length(); j++) {
            if (s1[i] == s2[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    
    cout << dp[s1.length() - 1][s2.length() - 1];
}