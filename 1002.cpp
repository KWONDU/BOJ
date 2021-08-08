#include <iostream>

using namespace std;

int T, x1, y1, r1, x2, y2, r2;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;

    while (T--) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        int d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        if (d == 0 && r1 == r2) cout << "-1\n";
        else if (d < (r1 - r2) * (r1 - r2)) cout << "0\n";
        else if (d == (r1 - r2) * (r1 - r2)) cout << "1\n";
        else if (d < (r1 + r2) * (r1 + r2)) cout << "2\n";
        else if (d == (r1 + r2) * (r1 + r2)) cout << "1\n";
        else cout << "0\n";
    }

    return 0;
}