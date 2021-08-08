#include <iostream>
#include <string>
using namespace std;

int N, p; string t;
bool chk[1048576];

void prnt(int num) {
	for (int i = 0; i < N; i++)
		cout << ((num >> i) & 1 ? 1 : 0);
	cout << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> t;
	for (int i = 0; i < N; i++)
		if (t[i] == '1') p += (1 << i);

	while (!chk[p]) {
		chk[p] = true;
		prnt(p);
		p = p ^ ((1 << N) - 1);
		chk[p] = true;
		prnt(p);

		for (int i = 0; i < N; i++) {
			int t = p ^ ((1 << N) - 1 - (1 << i));
			if (!chk[t]) {
				p = t;
				break;
			}
		}
	}

	return 0;
}
