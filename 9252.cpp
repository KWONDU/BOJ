#include <iostream>
#include <string>

using namespace std;

int max (int x, int y) {
    return x > y ? x : y;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    string a, b;
    cin >> a >> b;
    int lenA = a.length();
    int lenB = b.length();
    
    int dp[1000 + 1][1000 + 1];
    for (int i = 0; i <= lenA; i++) dp[i][0] = 0;
    for (int j = 0; j <= lenB; j++) dp[0][j] = 0;
    for (int i = 1; i <= lenA; i++)
        for (int j = 1; j <= lenB; j++) {
            if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    
    cout << dp[lenA][lenB] << "\n";
    
    int x = lenA;
    int y = lenB;
    string lcs = "";
    while (dp[x][y] > 0) {
        if (dp[x][y] == dp[x][y - 1]) y--;
        else if (dp[x][y] == dp[x - 1][y]) x--;
        else {
            lcs.push_back(a[x - 1]);
            x--;
            y--;
        }
    }
    
    for (int i = lcs.length() - 1; i >= 0; i--) cout << lcs[i];
    
    return 0;
}