#include <iostream>

using namespace std;

int a, b, c;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (true) {
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0) break;

        if (a * a + b * b == c * c || b * b + c * c == a * a || c * c + a * a == b * b) cout << "right\n";
        else cout << "wrong\n";
    }

    return 0;
}