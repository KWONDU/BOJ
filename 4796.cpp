#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int cnt = 0;
    int l, p, v;
    int maxday;
    while (true) {
        cin >> l >> p >> v;
        if (l == 0 && p == 0 && v == 0)
            break;
        
        cnt++;
        cout << "Case " << cnt << ": ";
        
        maxday = v / p * l;
        v %= p;
        if (v >= l)
            maxday += l;
        else
            maxday += v;
        
        cout << maxday << "\n";
    }
}