#include <iostream>

using namespace std;

int m, Seed, X1, X2;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> m >> Seed >> X1 >> X2;
	
	// a * (X1 - Seed) = (X2 - X1) % m, X1 - Seed의 m에 대한 역원 구하기
	// 1. (X1 - Seed)^(m - 2) % m (X)
	// 2. (X1 - Seed)s + mt = 1 통해서 s 구하기
	int rCur = ((X1 - Seed) % m + m) % m, rNxt = m;
	int sCur = 1, sNxt = 0, tCur = 0, tNxt = 1;
	while (rNxt != 0) {
		int q = rCur / rNxt;
		int temp = rCur;
		rCur = rNxt;
		rNxt = temp - rNxt * q;
		temp = sCur;
		sCur = sNxt;
		sNxt = temp - sNxt * q;
		temp = tCur;
		tCur = tNxt;
		tNxt = temp - tNxt * q;
	}
	
	long long int a = sCur;
	a = (a * (X2 - X1) % m) % m;
	a = (a + m) % m;
	cout << a << " ";
	long long int c = (X1 - a * Seed) % m;
	c = (c + m) % m;
	cout << c;
	
	return 0;
}