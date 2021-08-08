#include <iostream>
#include <vector>
#include <map>

using namespace std;

int min (int n1, int n2) {
    return n1 < n2 ? n1 : n2;
}

const int mod = 1e9;

int N, M;
long long int partA[1000 + 1], partB[1000 + 1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	bool isPrime[32000 + 1];
	vector<int> prime;
	for (int i = 1; i <= 32000; i++) isPrime[i] = true;
	isPrime[1] = false;
	for (int i = 2; i <= 32000; i++) {
	    if (!isPrime[i]) continue;
	    prime.push_back(i);
	    for (int j = i * 2; j <= 32000; j+=i) isPrime[j] = false;
	}
	
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> partA[i];
	cin >> M;
	for (int i = 1; i <= M; i++) cin >> partB[i];
	
	map<int, int> factorizationA, factorizationB;
	for (int p: prime) {
	    factorizationA.insert(make_pair(p, 0));
	    factorizationB.insert(make_pair(p, 0));
	}
	
	for (int a: partA) {
	    for (int p: prime) {
	        while (a > 1) {
	            if (a % p != 0) break;
	            a /= p;
	            factorizationA[p]++;
	        }
	    }
	    if (a > 1) {
            if (factorizationA.find(a) != factorizationA.end()) factorizationA[a]++;
            else factorizationA.insert(make_pair(a, 1));
        }
	}
	
	for (int b: partB) {
	    for (int p: prime) {
	        while (b > 1) {
	            if (b % p != 0) break;
	            b /= p;
	            factorizationB[p]++;
	        }
	    }
	    if (b > 1) {
            if (factorizationB.find(b) != factorizationB.end()) factorizationB[b]++;
            else factorizationB.insert(make_pair(b, 1));
        }
	}
	
	vector<pair<int, int>> ansFZ;
	for (auto iter = factorizationA.begin(); iter != factorizationA.end(); iter++) {
	    if (iter->second > 0 && factorizationB[iter->first] > 0) {
	        ansFZ.push_back(make_pair(iter->first, min(iter->second, factorizationB[iter->first])));
	    }
	}
	
	long long int ans = 1;
	bool chk = false;
	for (auto x : ansFZ) {
	    for (int i = 0; i < x.second; i++) {
	        if (!chk && ans * x.first >= mod) chk = true;
	        ans = (ans * x.first) % mod;
	    }
	}
	
	if (!chk) {
	    cout << ans;
	    return 0;
	}
	
	int ansArr[9]; for (int i = 0; i < 9; i++) ansArr[i] = 0;
	for (int i = 0; i < 9; i++) {
	    ansArr[i] = ans % 10;
	    ans /= 10;
	}
	
	for (int i = 8; i >= 0; i--) cout << ansArr[i];
	
	return 0;
}