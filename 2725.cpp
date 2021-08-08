#include <iostream>

using namespace std;

int C, N;

bool disjoint[1000 + 1][1000 + 1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	disjoint[0][0] = false, disjoint[1][0] = true, disjoint[0][1] = true;
	for (int i = 2; i <= 1000; i++) disjoint[i][0] = false;
	for (int j = 2; j <= 1000; j++) disjoint[0][j] = false;
	
	for (int i = 1; i <= 1000; i++) {
		for (int j = 1; j <= 1000; j++) {
			int n1 = i, n2 = j;
			while (n1 > 0 && n2 > 0) {
				if (n1 > n2) n1 %= n2;
				else n2 %= n1;
			}
			if ((n1 == 0 && n2 == 1) || (n1 == 1 && n2 == 0)) disjoint[i][j] = true;
			else disjoint[i][j] = false;
		}
	}
	
	cin >> C;
	while (C--) {
		cin >> N;
		
		int cnt = 0;
		for (int i = 0; i <= N; i++)
			for (int j = 0; j <= N; j++) if (disjoint[i][j]) cnt++;
		cout << cnt << "\n";
	}
	
	return 0;
}