#include <iostream>
#include <vector>

using namespace std;

const int mod = 987654321;

int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	bool isPrime[1000000 + 1];
	vector<int> prime;
	for (int i = 1; i <= 1e6; i++) isPrime[i] = true;
	isPrime[1] = false;
	for (int i = 2; i <= 1e6; i++) {
	    if (!isPrime[i]) continue;
	    for (int j = i * 2; j <= 1e6; j+=i) isPrime[j] = false;
	}
	for (int i = 1; i <= 1e6; i++) if (isPrime[i]) prime.push_back(i);
	
	cin >> N;
	
	vector<pair<int ,int>> fz;
	for (int p : prime) {
	    int tempCnt = 0, temp = N;
	    while (temp >= p) {
	        temp /= p;
	        tempCnt++;
	    }
	    if (tempCnt > 0) fz.push_back(make_pair(p, tempCnt));
	}
	
	long long int ans = 1;
	for (auto num : fz) {
	    for (int i = 0; i < num.second; i++) {
	        ans = (ans * num.first) % mod;
	    }
	}
	cout << ans;
	
	return 0;
}