#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

long long int dp[33][33];

int min (int n1, int n2) {
    return n1 < n2 ? n1 : n2;
}

int main() {
	int n, m;
    long long int l;

	cin >> n >> m >> l;

	for (int i = n; i >= 1; i--) {
		for (int j = min(m, i); j >= 0; j--) {
			if (j == m || i == n) {
				dp[i][j] = 1;
			}
			else {
				dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
			}

		}
	}
    
	for (int i = 1, j = 0; i <= n; i++) {
		if (dp[i][j] >= l) {
			cout << '0';
		}
		else {
			cout << '1';
			l -= dp[i][j];
			j++;
		}
	}


}