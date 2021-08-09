#include <iostream>
#include <memory.h>

using namespace std;

const int INF = 1<<31 - 1;

int N, r, c, dp[500][500];
pair<int, int> matrix[500][500];

int cal (int l, int r) {
    if (dp[l][r] != -1) return dp[l][r];

    if (l >= r) return dp[l][r] = 0;
    else if (l + 1 == r) return dp[l][r] = matrix[l][l].first * matrix[l][l].second * matrix[r][r].second;

    int ret = INF;
    for (int m = l; m + 1 <= r; m++) {
        ret = min(ret, cal(l, m) + cal(m + 1, r) + matrix[l][m].first * matrix[l][m].second * matrix[m + 1][r].second);
    }

    return dp[l][r] = ret;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> r >> c;
        matrix[i][i] = make_pair(r, c);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i > j) matrix[i][j] = make_pair(0, 0);
            else if (i == j) continue;
            else matrix[i][j] = make_pair(matrix[i][i].first, matrix[j][j].second);
        }
    }

    for (int i = 0; i < 500; i++) memset(dp[i], -1, sizeof(dp[i]));

    cout << cal(0, N - 1);

    return 0;
}