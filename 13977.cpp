#include <iostream>

using namespace std;

const int mod = 1e9 + 7;

int M, N, K;

long long int fac[4000000 + 1];
long long int inv[4000000 + 1];

long long int powMOD (long long int base, int exponent) {
	if (exponent == 0) return 1;
	
	long long int powMODhalf = powMOD(base, exponent / 2);
	if (exponent % 2 == 0) return (powMODhalf * powMODhalf) % mod;
	else return ((powMODhalf * powMODhalf) % mod * base) % mod;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	fac[0] = 1;
	for (int i = 1; i <= 4000000; i++) {
		fac[i] = (fac[i - 1] * i) % mod;
	}
	
	inv[0] = 1;
	for (int i = 1; i <= 4000000; i++) {
		inv[i] = powMOD(fac[i], mod - 2);
	}
	
	cin >> M;
	while (M--) {
		cin >> N >> K;
		cout << ((fac[N] * inv[K]) % mod * inv[N - K]) % mod << "\n";
	}
	
	return 0;
}