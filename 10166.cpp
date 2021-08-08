#include <iostream>

using namespace std;

int D1, D2;

bool irF[2000 + 1][2000 + 1];

int gcd (int n1, int n2) {
	while (n1 > 0 && n2 > 0) {
		if (n1 > n2) n1 %= n2;
		else n2 %= n1;
	}
	if (n1 == 0) return n2;
	else return n1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> D1 >> D2;
	
	for (int i = 1; i <= 2000; i++)
		for (int j = 1; j <= 2000; j++) irF[i][j] = false;
	
	for (int i = D1; i <= D2; i++)
		for (int j = 1; j <= i; j++) {
			int gcdIJ = gcd(i, j);
			if (!irF[i / gcdIJ][j / gcdIJ]) irF[i / gcdIJ][j / gcdIJ] = true;
		}
	
	int cnt = 0;
	for (int i = 1; i <= 2000; i++)
		for (int j = 1; j <= 2000; j++) if (irF[i][j]) cnt++;
	cout << cnt;
	
	return 0;
}