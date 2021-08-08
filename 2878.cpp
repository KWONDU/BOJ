#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long int minv (long long int a, long long int b) {
    if (a < b)
        return a;
    else
        return b;
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int m, n;
    cin >> m >> n;
    int candy[100000];
    long long int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> candy[i];
        sum += candy[i];
    }
    
    long long int ans = 0;
    
    sort(candy, candy + n);
    long long int temp;
    long long int left = sum - m;
    for (int i = 0; i < n; i++) {
        temp = minv(candy[i], left / (n - i));
        ans += temp * temp;
        left -= temp;
    }
    
    cout << ans;
}