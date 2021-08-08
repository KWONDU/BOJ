#include <iostream>

using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	// (n - 1) / 1 + 1  +  --- + (n - 1) / k + 1  +  ---  +  (n - 1) / n + 1
	// n + sigma_k=1->n [(n - 1) / k]
	long long int ans = n, len;
	for (int i = 1; i < n; i+=len) {
        // ((n - 1) / k) * k + (n - 1) % k => k 번째
        // ((n - 1) / k) * (k + 1) + ((n - 1) % k - (n - 1) / k) => (k + 1) 번째
        // 1 증가할 때마다 (n - 1) / k 씩 감소한다
        // (n - 1) % k, (n - 1) % k - (n - 1) / k, ---, 최솟값
        // 0 부터 (((n - 1) % k) / ((n - 1) / k))(=len) * (n - 1) / k 까지 len + 1 개
        // [[ i = n 일 때는 (n - 1) / i = 0 이 되므로 Division By Zero Error 발생
        // 어차피 값이 0 이므로 계산하지 않는다 (((n - 1) / n) * len = 0 * len = 0) ]]
        len = ((n - 1) % i) / ((n - 1) / i) + 1;
        ans += ((n - 1) / i) * len;
    }
	cout << ans;
	
	return 0;
}