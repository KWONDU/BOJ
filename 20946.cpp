#include <iostream>
#include <vector>

using namespace std;

bool isPrime[1000000 + 1];
vector<long long int> prime;

long long int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	for (int i = 1; i <= 1000000; i++) isPrime[i] = true;
	isPrime[1] = false;
	for (int i = 2; i <= 1000000; i++) {
		if (!isPrime[i]) continue;
		prime.push_back(i);
		for (int j = i * 2; j <= 1000000; j+=i) isPrime[j] = false;
	}
	
	cin >> N;
	
	long long int temp = N;
	vector<long long int> factorization;
	for (long long int p : prime) {
		if (p * p > N || temp == 1) break;
		while (temp > 1 && temp % p == 0) {
			temp /= p;
			factorization.push_back(p);
		}
	}
	if (temp > 1) factorization.push_back(temp);
	
	int pos = 0, len = factorization.size();
	if (len == 1) cout << "-1";
	else if (len == 2) cout << (factorization[0] * factorization[1]);
	else {
		while (pos + 3 < len - 1) {
			cout << (factorization[pos] * factorization[pos + 1]) << " ";
			pos += 2;
		}
		if (len % 2 == 0) {
			cout << (factorization[len - 4] * factorization[len - 3]) << " ";
			cout << (factorization[len - 2] * factorization[len - 1]);
		} else cout << (factorization[len - 3] * factorization[len - 2] * factorization[len - 1]);
	}
	
	return 0;
}