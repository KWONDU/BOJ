#include <iostream>

using namespace std;

int T, N, M;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;

    while (T--) {
        cin >> N >> M;

        if (N > M - N) N = M - N;

        long long int ans = 1;
        for (int i = M - N + 1; i <= M; i++) ans *= i;
        for (int j = 1; j <= N; j++) ans /= j;
        cout << ans << "\n";
    }

    return 0;
}