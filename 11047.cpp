#include <iostream>
#include <algorithm>

using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    int price[10];
    for (int i = 0; i < n; i++)
        cin >> price[i];
    
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        cnt += k / price[i];
        k %= price[i];
        
        if (k == 0)
            break;
    }
    
    cout << cnt;
}