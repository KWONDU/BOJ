#include <iostream>
#include <memory.h>

using namespace std;

int N, a[16], b[16], dp[1<<16];

bool chk (int bit, int target) {
    if (bit & 1<<target) return false;

    for (int i = 0; i < target; i++) {
        if (!(bit & 1<<i) && a[target] % a[i] == 0) return false;
    }

    return true;
}

int cal (int bit, int rnd) {
    if (dp[bit] != -1) return dp[bit];

    if (rnd > N) return 0;
    
    int ret = 0;
    for (int tar = 0; tar < N; tar++) {
        if (chk(bit, tar)) ret = max(ret, cal(bit | 1<<tar, rnd + 1) + b[tar] * rnd);
    }
    
    return dp[bit] = ret;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> a[i] >> b[i];
    
    memset(dp, -1, sizeof(dp));

    cout << cal(0, 1);

    return 0;
}