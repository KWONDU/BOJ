#include <iostream>

using namespace std;

const int mod = 10007;

int N, K, comb[1000 + 1][1000 + 1];

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;

    for (int i = 0; i <= N; i++) {
        comb[i][0] = 1, comb[i][i] = 1;
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 1; j < N; j++) comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
    }

    cout << (comb[N][K] % mod);

    return 0;
}