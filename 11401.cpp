#include <iostream>

using namespace std;

const int mod = 1e9 + 7;

int N, K;
long long int fac[4000000 + 1];

long long int power (long long int base, long long int exp) {
    if (exp == 0) return 1;
    long long int temp = power(base, exp / 2) % mod;
    if (exp % 2 == 0) return temp * temp % mod;
    else return (temp * temp % mod) * base % mod;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;

    fac[0] = 1;
    for (int i = 1; i <= N; i++) fac[i] = (fac[i - 1] * i) % mod;

    long long int ans = fac[N];
    ans = ans * power(fac[K] * fac[N - K] % mod, mod - 2) % mod;
    cout << (ans % mod);

    return 0;
}