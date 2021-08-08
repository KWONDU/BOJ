#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

const int mod = 9901;
const int MAX = 14;

int n, m;
int dp[MAX * MAX][1<<MAX];

int domino (int i, int state) {
    if (i == n * m && state == 0) return 1;
    if (i >= n * m) return 0;
    
    int& re = dp[i][state];
    if (re != -1) return re;
    
    if (state & 1)
        re = domino(i + 1, state>>1);
    else {
        re = domino(i + 1, state>>1 | 1<<m - 1);
        if (i % m != m - 1 && !(state & 3))
            re += domino(i + 1, state>>1 | 1);
    }
    
    re %= mod;
    return re;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    for (int i = 0; i < MAX * MAX; i++)
        for (int j = 0; j < 1<<MAX; j++) dp[i][j] = -1;
    cout << domino(0, 0);
    
    return 0;
}