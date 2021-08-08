#include <iostream>
#include <string>

using namespace std;

int N, K;
bool visit[30 + 1][30 + 1][30 + 1][30 * 29 / 2 + 1];
char ans[30];

bool dp (int len, int cntA, int cntB, int cntC, int sol) {
    if (len == N) {
        if (sol == K) return true;
        else return false;
    }
    
    if (visit[cntA][cntB][cntC][sol]) return false;
    visit[cntA][cntB][cntC][sol] = true;
    
    ans[len] = 'A';
    if (dp(len + 1, cntA + 1, cntB, cntC, sol)) return true;
    
    ans[len] = 'B';
    if (dp(len + 1, cntA, cntB + 1, cntC, sol + cntA)) return true;
    
    ans[len] = 'C';
    if (dp(len + 1, cntA, cntB, cntC + 1, sol + cntA + cntB)) return true;
    
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> K;
    
    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= N; j++)
            for (int k = 0; k <= N; k++)
                for (int l = 0; l <= K; l++) visit[i][j][k][l] = false;
    
    if (dp(0, 0, 0, 0, 0)) cout << ans;
    else cout << "-1";
    
    return 0;
}