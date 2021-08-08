#include <iostream>
#include <memory.h>
#include <utility>
#include <vector>

using namespace std;

long long int dp[100000 + 1][10 + 1];

int N, M, K, S, T, a, b, t;
vector<pair<int, int>> adj[100000 + 1];
vector<int> adjRe[100000 + 1];

long long int max (long long int ll1, long long int ll2) {
    return ll1 > ll2 ? ll1 : ll2;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K >> S >> T;
    while (M--) {
        cin >> a >> b >> t;
        adj[a].push_back(make_pair(b, t));
        adjRe[b].push_back(a);
    }
    
    for (int i = 0; i <= 100000; i++) memset(dp[i], -1, sizeof(dp[i]));
    
    // dp k=1~
    dp[S][0] = 0;
    for (int cnt = 0; cnt <= K; cnt++) {
        if (cnt > 0) {
            for (int cur = N; cur >= 1; cur--) {
                for (int nxt : adjRe[cur]) dp[nxt][cnt] = max(dp[nxt][cnt], dp[cur][cnt - 1]);
            }
        }
        
        for (int cur = 1; cur <= N; cur++) {
            if (dp[cur][cnt] == -1) continue;
            
            for (auto nxt : adj[cur]) dp[nxt.first][cnt] = max(dp[nxt.first][cnt], dp[cur][cnt] + nxt.second);
        }
    }
    
    cout << dp[T][K];
    
    return 0;
}