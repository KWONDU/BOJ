#include <iostream>

using namespace std;

int N, M, K;

int dp[100 + 100 + 1][100 + 100 + 1];

int min (int n1, int n2) {
    return n1 < n2 ? n1 : n2;
}

int combination (int i, int j) {
    if (dp[i][j] != -1) return dp[i][j];
    
    if (i < j) return dp[i][j] = 0;
    else if (j == 0 || i == j) return dp[i][j] = 1;
    else return dp[i][j] = min(K + 1, combination(i - 1, j - 1) + combination(i - 1, j));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> K;
    
    for (int i = 0; i <= N + M; i++)
        for (int j = 0; j <= N + M; j++) dp[i][j] = -1;
    
    for (int i = 0; i <= N + M; i++)
        for (int j = 0; j <= N + M; j++) combination(i, j);
    
    if (K > dp[N + M][N]) {
        cout << "-1";
        return 0;
    }
    
    int cntA = N, cntZ = M;
    while (cntA > 0 && cntZ > 0) {
        if (K > dp[cntA + cntZ - 1][cntA - 1]) {
            cout << "z";
            K -= dp[cntA + cntZ - 1][cntA - 1];
            cntZ--;
        } else {
            cout << "a";
            cntA--;
        }
    }
    
    while (cntA-- > 0) cout << "a";
    while (cntZ-- > 0) cout << "z";
    
    return  0;
}