#include <iostream>

using namespace std;

int N, M;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    int gcd, tempN = N, tempM = M;
    while (N > 0 && M > 0) {
        if (N > M) N %= M;
        else M %= N;
    }

    if (N == 0) gcd = M;
    else gcd = N;

    cout << gcd << "\n" << (tempN * tempM / gcd);

    return 0;
}