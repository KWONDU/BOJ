#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1000000 * 300 + 1;
const int MAX = 300 + 1;

int n, m, dp[MAX][MAX][2][MAX];
vector<int> x;

int cal (int l, int r, int chk, int remain) {
    if (dp[l][r][chk][remain] != -1) return dp[l][r][chk][remain];
    
    if (remain == 1) return dp[l][r][chk][remain] = 0;
    
    int pos = (chk == 0 ? l : r);
    
    int ret = INF;
    if (l - 1 >= 0) ret = min(ret, cal(l - 1, r, 0, remain - 1) + (x[pos] - x[l - 1]) * (remain - 1));
    if (r + 1 <= n - 1) ret = min(ret, cal(l, r + 1, 1, remain - 1) + (x[r + 1] - x[pos]) * (remain - 1));
    
    return dp[l][r][chk][remain] = ret;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    
    bool zeroChk = false;
    x.push_back(0);
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (temp == 0) zeroChk = true;
        else x.push_back(temp);
    }
    
    if (!zeroChk) n++;
    
    sort(x.begin(), x.end());
    
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < MAX; l++) dp[i][j][k][l] = -1;
            }
        }
    }
    
    int zeroPos = find(x.begin(), x.end(), 0) - x.begin();
    
    int ans = 0;
    for (int cnt = 1; cnt <= n; cnt++) {
        int taken = min(cal(zeroPos, zeroPos, 0, cnt), cal(zeroPos, zeroPos, 1, cnt));
        if (!zeroChk) ans = max(ans, (cnt - 1) * m - taken);
        else ans = max(ans, cnt * m - taken);
    }
    
    cout << ans;
    
    return 0;
}