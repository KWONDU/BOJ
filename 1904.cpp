#include <iostream>

using namespace std;

const int mod = 15746;

int N;
long long int bi[1000000];

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    if (N == 1) bi[0] = 1;
    else if (N == 2) {
        bi[0] = 1;
        bi[1] = 2;
    } else {
        bi[0] = 1;
        bi[1] = 2;
        for (int i = 2; i < N; i++) bi[i] = bi[i - 1] % mod + bi[i - 2] % mod;
    }

    cout << bi[N - 1] % mod;

    return 0;
}