#include <iostream>

using namespace std;

int T, N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> T;
	while (T--) {
		cin >> N;
		
		int cnt = 0;
		while (N > 0) {
			cnt += N / 5;
			N /= 5;
		}
		cout << cnt << "\n";
	}
	
	return 0;
}