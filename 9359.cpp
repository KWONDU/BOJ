#include <iostream>
#include <vector>

using namespace std;

int T, N;
long long int A, B;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	bool isPrime[32000 + 1];
	vector<int> prime;
	for (int i = 1; i <= 32000; i++) isPrime[i] = true;
	isPrime[1] = false;
	for (int i = 1; i <= 32000; i++) {
		if (!isPrime[i]) continue;
		prime.push_back(i);
		for (int j = 2; j * i <= 32000; j++) isPrime[j * i] = false;
	}
	
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> A >> B >> N;
		
		vector<int> factor;
		for (int p: prime) {
			bool chk = false;
			while (N > 1) {
				if (N % p != 0) break;
				chk = true;
				N /= p;
			}
			if (chk) factor.push_back(p);
		}
		if (N > 1) factor.push_back(N);
		
		long long int cnt = 0;
		vector<long long int> pFChk;
		pFChk.push_back(1);
		for (int f: factor) {
		    int tempSize = pFChk.size();
			for (int i = 0; i < tempSize; i++) {
			    long long int temp = f * pFChk[i];
			    cnt += (B / temp) - (A / temp);
			    if ((A % temp) == 0) {
			        if (temp > 0) cnt++;
			        else cnt--;
			    }
			    pFChk.push_back(-temp);
			}
		}
		
		cout << "Case #" << t << ": " << (B - A + 1 - cnt) << "\n";
	}
	
	return 0;
}