#include <iostream>

using namespace std;

int T, M, N, x, y;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> T;
	while (T--) {
		cin >> M >> N >> x >> y;
		
		bool chk = false;
		for (int i = 0; i < N; i++) {
			if (x % N == y % N) {
				chk = true;
				break;
			} else x+=M;
		}
		
		if (!chk) cout << "-1\n";
		else cout << x << "\n";
	}
	
	return 0;
}