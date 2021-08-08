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
    int* a = new int[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    
    int pos1 = 0; int pos2 = 0;
    int sum = a[0], cnt = 0;
    while (pos2 < n) {
        if (sum < m) {
            pos2++;
            sum += a[pos2];
        }
        else if (sum == m) {
            pos2++;
            sum += a[pos2];
            cnt++;
        }
        else {
            sum -= a[pos1];
            pos1++;
        }
    }
    
    cout << cnt;
}