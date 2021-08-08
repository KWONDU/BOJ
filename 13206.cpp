#include <iostream>
#include <vector>

using namespace std;

const int mod = 1e9 + 7;

int T, N;
int natural[1000000 + 1];

bool isPrime[1000 + 1];
vector<int> prime;

int max (int n1, int n2) {
	return n1 > n2 ? n1 : n2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	for (int i = 1; i <= 1000; i++) isPrime[i] = true;
	isPrime[1] = false;
	for (int i = 2; i * i<= 1000; i++) {
		if (!isPrime[i]) continue;
		for (int j = i * 2; j <= 1000; j+=i) isPrime[j] = false;
	}
	for (int i = 1; i <= 1000; i++) if (isPrime[i]) prime.push_back(i);
	
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; i++) cin >> natural[i];
		
		int cnt[1000 + 1];
		for (int i = 1; i <= 1000; i++) cnt[i] = 0;
		for (int i = 1; i <= N; i++) {
			int temp = natural[i], tempCnt = 0;
			for (int p : prime) {
				if (temp == 1) break;
				tempCnt = 0;
				while (temp > 1 && temp % p == 0) {
					tempCnt++;
					temp /= p;
				}
				cnt[p] = max(cnt[p], tempCnt);
			}
		}
		
		long long ans = 1;
		for (int p : prime)
			for (int i = 0; i < cnt[p]; i++) ans = (ans * p) % mod;
		cout << ans << "\n";
	}
	
	return 0;
}