#include <iostream>
#include <vector>

using namespace std;

int profit[300 + 1][20 + 1];
long long int dp[300 + 1][20 + 1];
int invest[300 + 1][20 + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> i;
        for (int j = 1; j <= M; j++) cin >> profit[i][j];
    }
    
    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= M; j++) {
            dp[i][j] = 0;
            invest[i][j] = 0;
        }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            for (int k = 0; k <= i; k++) {
                if (dp[i][j] < profit[k][j] + dp[i - k][j - 1]) {
                    invest[i][j] = k;
                    dp[i][j] = profit[k][j] + dp[i - k][j - 1];
                }
            }
        }
    }
    
    cout << dp[N][M] << "\n";
    
    vector<int> ans;
    int money = N;
    for (int j = M; j >= 1; j--) {
        ans.push_back(invest[money][j]);
        money -= invest[money][j];
    }
    
    for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << " ";
    
    return 0;
}