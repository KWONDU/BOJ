#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define MAX 16
const int INF = 1<<30;

int n;
int w[MAX][MAX];
int dp[MAX][1<<MAX];

int tsp (int cur, int visited) {
    int &chk = dp[cur][visited];
    
    if (chk != -1) return chk;
    
    if (visited == (1<<n) - 1) {
        if (w[cur][0] != 0) return w[cur][0];
        else return INF;
    }
    
    chk = INF;
    for (int i = 0; i < n; i++) {
        if (visited & (1<<i) || w[cur][i] == 0) continue;
        chk = min(chk, tsp(i, visited | (1<<i)) + w[cur][i]);
    }
    
    return chk;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> w[i][j];
    
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < 1<<MAX; j++) dp[i][j] = -1;
    
    cout << tsp(0, 1);
    
    return 0;
}