#include <iostream>
#include <cmath>

using namespace std;

int T, x, y;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;

    while (T--) {
        cin >> x >> y;

        int dis = y - x;
        int n = sqrt(dis);
        int re = dis - n * n;

        if (re % n == 0) cout << ((2 * n - 1) + re / n) << "\n";
        else cout << ((2 * n - 1) + re / n + 1) << "\n";
    }

    return 0;
}