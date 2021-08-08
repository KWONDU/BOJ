#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int mod = 1000000009;
    
    int t;
    cin >> t;
    
    int* arr = new int[1000000 + 1];
    arr[1] = 1; arr[2] = 2; arr[3] = 4;
    int n;
    for (int i = 0; i < t; i++) {
        cin >> n;
        
        for (int j = 1; j <= n; j++)
            if (arr[j] == 0) {
                arr[j] = ((arr[j - 1] + arr[j - 2]) % mod + arr[j - 3]) % mod;
            }
        cout << arr[n] << "\n";
    }
}