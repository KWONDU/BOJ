#include <iostream>

using namespace std;

const long long int INF = 7.575e12 + 1;
const int MAX = 100 + 1;

int T, N, a;
long long int prefix[MAX][MAX], dp[MAX + 1][MAX + 1][2];

long long int cal (int l, int r, bool chk) {
    if (dp[l][r][chk] != -1) return dp[l][r][chk];
    
    if (l == 1 && r == N) return dp[l][r][chk] = 0;
    
    // 함수 호출 한 번 당 1~N 전체를 다 조사하면
    // dp 값이 계속 변하고 단순 time complexity도 너무 큼 => 시간 초과
    // 한 칸씩 갱신
    
    int pos = (chk ? r : l);
    
    long long int ret = INF;
    if (l - 1 >= 1) ret = min(ret, cal(l - 1, r, false) + prefix[l - 1][pos] * (N - (r - l + 1)));
    if (r + 1 <= N) ret = min(ret, cal(l, r + 1, true) + prefix[pos][r + 1] * (N - (r - l + 1)));
    
    return dp[l][r][chk] = ret;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> N >> a;
        for (int i = 1; i <= N; i++) prefix[i][i] = 0;
        for (int i = 1; i <= N - 1; i++) cin >> prefix[i][i + 1];
        for (int i = 1; i <= N; i++) {
            for (int j = i + 2; j <= N; j++) prefix[i][j] = prefix[i][j - 1] + prefix[j - 1][j];
        }
        
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                for (int k = 0; k < 2; k++) dp[i][j][k] = -1;
            }
        }
        
        cout << min(cal(a, a, false), cal(a, a, true)) << "\n";
    }
    
    return 0;
}