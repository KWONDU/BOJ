#include <iostream>
#include <vector>

using namespace std;

int T, N, K, X, Y, W;
int D[1000 + 1];

int dp[1000 + 1];
int cal (vector<int> vR[], int cur) {
    if (dp[cur] != -1) return dp[cur];
    
    dp[cur] = D[cur];
    for (int prev : vR[cur]) {
        dp[cur] = max(dp[cur], cal(vR, prev) + D[cur]);
    }
    
    return dp[cur];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> T;
    while (T--) {
        vector<int> VReverse[1000 + 1];
        
        cin >> N >> K;
        for (int i = 1; i <= N; i++) cin >> D[i];
        for (int i = 1; i <= K; i++) {
            cin >> X >> Y;
            VReverse[Y].push_back(X);
        }
        cin >> W;
        
        for (int i = 1; i <= N; i++) dp[i] = -1;
        
        cout << cal(VReverse, W) << "\n";
    }
    
    return 0;
}