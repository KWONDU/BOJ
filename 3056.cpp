#include <iostream>
#include <memory.h>

using namespace std;

int N, per[20][20];
double dp[1<<20];

double cal (int bit, int cur) {
    if (dp[bit] != 0) return dp[bit];

    if (cur >= N) return dp[bit] = 1;

    double ret = 0;
    for (int ms = 0; ms < N; ms++) {
        if (!(bit & 1<<ms)) ret = max(ret, cal(bit | 1<<ms, cur + 1) * ((double)per[cur][ms] / 100));
    }

    return dp[bit] = ret;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin >> per[i][j];
    }
    
    memset(dp, 0, sizeof(dp));

    cout << fixed;
    cout.precision(6);
    cout << cal(0, 0) * 100;

    return 0;
}