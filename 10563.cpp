#include <iostream>

using namespace std;

const int MAX = 100;

int T, N, state[MAX + 2], a;
int dp[MAX + 1][MAX + 1][2];

int cal (int s, int e, int remainChk) {
    if (dp[s][e][remainChk] != -1) return dp[s][e][remainChk];
    
    if (s == e) return dp[s][e][remainChk] = 1;
    
    int ret = 0;
    for (int m = s; m <= e; m++) {
        if (state[m - 1] < state[m] && state[m] > state[m + 1]) {
            int temp = state[m];
            state[m] = 0;
            if (a <= m - 1) ret |= (1 - cal(s, m - 1, (remainChk + e - m) % 2));
            else ret |= (1 - cal(m + 1, e, (remainChk + m - s) % 2));
            state[m] = temp;
        }
    }
    
    // remainChk = 0인 경우 => 최종적으로 남아있는 게 0개인 경우와 같아짐
    if (remainChk == 1) ret |= (1 - cal(s, e, 0));
    
    return dp[s][e][remainChk] = ret;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    
    while (T--) {
        cin >> N;
        state[0] = 0;
        for (int i = 1; i <= N; i++) {
            cin >> state[i];
            if (state[i] == 1) a = i;
        }
        state[N + 1] = 0;
        
        for (int i = 1; i <= MAX; i++) {
            for (int j = 1; j <= MAX; j++) {
                for (int k = 0; k < 2; k++) dp[i][j][k] = -1;
            }
        }
        
        cout << (cal(1, N, 0) == 1 ? "Alice" : "Bob") << "\n";
    }

    return 0;
}