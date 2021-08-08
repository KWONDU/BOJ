#include <iostream>

using namespace std;

int T, k, n;

int func (int K, int N) {
    if (K == 0) return N;

    int sum = 0;
    for (int i = 0; i <= N; i++) sum += func(K - 1, i);
    return sum;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;

    while (T--) {
        cin >> k >> n;

        cout << func(k, n) << "\n";
    }

    return 0;
}