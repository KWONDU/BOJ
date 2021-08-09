#include <iostream>
#include <memory.h>

using namespace std;

const int INF = 16 * 16 * 1e6 + 1;

int N, W[16][16], dp[1<<16][16], start;

int TSP (int bit, int cur) {
    if (dp[bit][cur] != INF) return dp[bit][cur];

    if (bit == (1<<N) - 1) {
        if (W[cur][start] > 0) return dp[bit][cur] = W[cur][start];
        else return dp[bit][cur] = INF;
    }

    int ret = INF;
    for (int nxt = 0; nxt < N; nxt++) {
        if (!(bit & 1<<nxt) && W[cur][nxt] > 0) ret = min(ret, TSP(bit | 1<<nxt, nxt) + W[cur][nxt]);
    }

    return dp[bit][cur] = ret;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin >> W[i][j];
    }

    for (int i = 0; i < 1<<16; i++) {
        for (int j = 0; j < 16; j++) dp[i][j] = INF;
    }

    start = 0;
    cout << TSP(1, start);

    return 0;
}