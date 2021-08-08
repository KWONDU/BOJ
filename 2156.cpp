#include <iostream>

using namespace std;

int N, wine[10000 + 1], sum[10000 + 1][3];

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> wine[i];

    if (N == 1) {
        sum[1][0] = wine[1];
    } else if (N == 2) {
        sum[2][0] = wine[2];
        sum[2][1] = wine[1] + wine[2];
        sum[2][2] = wine[1];
    } else {
        for (int i = 3; i <= N; i++) {
            sum[1][0] = wine[1];
            sum[2][0] = wine[2];
            sum[2][1] = wine[1] + wine[2];
            sum[2][2] = wine[1];
            sum[i][0] = sum[i - 1][2] + wine[i];
            sum[i][1] = sum[i - 1][0] + wine[i];
            sum[i][2] = max(sum[i - 1][0], max(sum[i - 1][1], sum[i - 1][2]));
        }
    }

    cout << max(sum[N][0], max(sum[N][1], sum[N][2]));

    return 0;
}