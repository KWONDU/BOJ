#include <iostream>

using namespace std;

int n1, n2;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (true) {
        cin >> n1 >> n2;
        if (n1 == 0 && n2 == 0) break;

        if (n1 < n2 && n2 % n1 == 0) cout << "factor\n";
        else if (n1 > n2 && n1 % n2 == 0) cout << "multiple\n";
        else cout << "neither\n";
    }

    return 0;
}