#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    int p[1000];
    for (int i = 0; i < n; i++) cin >> p[i];
    
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= p[i]; j++) {
            p[i] -= j;
            int ans = p[0];
            for (int chk = 1; chk < n; chk++) ans = ans ^ p[chk];
            if (ans == 0) cnt++;
            p[i] += j;
        }
    }
    
    cout << cnt;
    
    return 0;
}