#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    
    int cnt = 0;
    int pos1, pos2;
    for (int chk = 0; chk < n; chk++) {
        pos1 = 0; pos2 = n - 1;
        while (pos1 < pos2) {
            if (pos1 == chk) {
                pos1++;
                continue;
            }
            else if (pos2 == chk) {
                pos2--;
                continue;
            }
            
            if (a[pos1] + a[pos2] < a[chk])
                pos1++;
            else if (a[pos1] + a[pos2] == a[chk]) {
                cnt++;
                break;
            }
            else
                pos2--;
        }
    }
    
    cout << cnt;
}