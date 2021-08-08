#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    int* t = new int[n];
    for (int i = 0; i < n; i++)
        cin >> t[i];
    
    long long int left = 1;
    long long int right = 1e18;
    long long int mid;
    long long int ans = right;
    while (left <= right) {
        mid = (left + right) / 2;
        long long int total = 0;
        for (int i = 0; i < n; i++) {
            total += mid / t[i];
            if (total >= m)
                break;
        }
        
        if (total >= m) {
            if (ans > mid)
                ans = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    
    cout << ans;
}