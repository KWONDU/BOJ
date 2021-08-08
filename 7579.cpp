#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    int* memory = new int[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> memory[i];
    int* cost = new int[n + 1];
    int totalcost = 0;
    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
        totalcost += cost[i];
    }
    
    int dp[100 + 1][10000 + 1]{};
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= totalcost; j++) {
            if (j < cost[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + memory[i]);
        }
    }
    
    int mincost = totalcost + 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= totalcost; j++) {
            if (dp[i][j] >= m) {
                if (mincost > j)
                    mincost = j;
            }
        }
    cout << mincost;
}