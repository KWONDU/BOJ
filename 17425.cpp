#include <iostream>

using namespace std;

int T, N;

long long int f[1000000 + 1];
long long int g[1000000 + 1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	for (int i = 1; i <= 1000000; i++) f[i] = 0;
	for (int i = 1; i <= 1000000; i++)
		for (int j = 1; j * i <= 1000000; j++) f[j * i]+=i;
	g[0] = 0;
	for (int i = 1; i <= 1000000; i++) g[i] = g[i - 1] + f[i];
	
	cin >> T;
	while (T--) {
		cin >> N;
		cout << g[N] << "\n";
	}
	
	return 0;
}