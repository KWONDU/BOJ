#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int m, n;
    cin >> m >> n;
    int* l = new int[n];
    int right = 0;
    for (int i = 0; i < n; i++) {
        cin >> l[i];
        if (l[i] > right)
            right = l[i];
    }
    
    int ans = 0;
    
    int left = 1;
    int mid;
    while (left <= right) {
        mid = (left + right) / 2;
        long long int sum = 0;
        for (int i = 0; i < n; i++)
            sum += l[i] / mid;
        
        if (sum >= m) {
            ans = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    
    cout << ans;
}