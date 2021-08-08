#include <iostream>

using namespace std;

int h, m;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> h >> m;
    
    if (m >= 45) m -= 45;
    else if (h > 0) {
        h --;
        m += 15;
    } else {
        h = 23;
        m += 15;
    }
    cout << h << " " << m;
}