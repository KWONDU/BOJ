#include <iostream>
#include <vector>

using namespace std;

bool chk[1003001 + 1];
vector<int> prime;

int N;

bool palindrome(int n) {
	vector<int> num;
	while (n > 0) {
		num.push_back(n % 10);
		n /= 10;
	}
	
	for (int i = 0; i < num.size(); i++)
		if (num[i] != num[num.size() - 1 - i]) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	for (int i = 1; i <= 1003001; i++) chk[i] = true;
	chk[1] = false;
	for (int i = 1; i <= 1003001; i++) {
		if (!chk[i]) continue;
		prime.push_back(i);
		for (int j = 2; j * i <= 1003001; j++) chk[j * i] = false;
	}
	
	cin >> N;
	
	for (int p: prime) {
		if (p < N) continue;
		if (palindrome(p)) {
			cout << p << "\n";
			break;
		}
	}
	
	return 0;
}