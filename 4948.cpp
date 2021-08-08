#include <iostream>
#include <vector>

using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	while (true) {
		cin >> n;
		if (n == 0) break;
		
		int cnt = 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			bool chk = true;
			for (int j = 2; j * j <= i; j++) {
				if (i % j == 0) {
					chk = false;
					break;
				}
			}
			if (chk) cnt++;
		}
		
		cout << cnt << "\n";
	}
	
	return 0;
}