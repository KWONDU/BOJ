#include <iostream>
#include <cmath>

#define M_PI 3.14159265358979323846

using namespace std;

int T, k;
long double a, b;

long double max (long double ld1, long double ld2) {
    return ld1 > ld2 ? ld1 : ld2;
}

long double max (long double ld1, long double ld2, long double ld3) {
    return max(max(ld1, ld2), ld3);
}

void input () {
    cin >> a >> b >> k;
    
    return ;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    
    cout << fixed;
    cout.precision(7);
    
    while (T--) {
        input();
        
        long double r = (a * b) / (a + b + sqrt(a * a + b * b));
        long double d1 = r * sqrt(2);
        long double d2 = sqrt((a - r) * (a - r) + r * r);
        long double d3 = sqrt((b - r) * (b - r) + r * r);
        
        long double prev1 = r, prev2 = r, prev3 = r;
        long double cur1, cur2, cur3, nxt;
        for (int i = 2; i <= k; i++) {
            cur1 = prev1 * (d1 - prev1) / (d1 + prev1);
            cur2 = prev2 * (d2 - prev2) / (d2 + prev2);
            cur3 = prev3 * (d3 - prev3) / (d3 + prev3);
            
            r = max(cur1, cur2, cur3);
            if (cur1 == r) {
                d1 -= (prev1 + cur1);
                prev1 = cur1;
            } else if (cur2 == r) {
                d2 -= (prev2 + cur2);
                prev2 = cur2;
            } else {
                d3 -= (prev3 + cur3);
                prev3 = cur3;
            }
        }
        
        cout << M_PI * r * r << "\n";
    }
    
    return 0;
}