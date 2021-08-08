#include <iostream>

using namespace std;

long long int N, k;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> k;
    long long int left = 1;
    long long int right = N * N;
    long long int mid = (left + right) / 2;
    long long int ans = 0;
    while (left <= right) {
        mid = (left + right) / 2;
        long long int q = mid / N;
        long long int cnt = q * N;
        for (long long int i = q + 1; i <= N; i++)
            cnt += mid / i;
        
        if (k > cnt)
            left = mid + 1;
        else if (k <= cnt) {
            ans = mid;
            right = mid - 1;
        }
    }
    cout << ans;
    
    return 0;
}