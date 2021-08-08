#include <iostream>

using namespace std;

int K, N, wires[10000];
long long int r = 0, l = 1, m;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> K >> N;
    for (int i = 0; i < K; i++) {
        cin >> wires[i];
        r += wires[i];
    }

    int cnt = 0;
    long long int len = 1;
    while (l <= r) {
        m = (l + r) / 2;
        cnt = 0;
        for (int i = 0; i < K; i++) cnt += wires[i] / m;

        if (cnt < N) r = m - 1;
        else {
            if (m > len) len = m;
            l = m + 1;
        }
    }

    cout << len;

    return 0;
}