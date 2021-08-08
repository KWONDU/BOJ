#include <iostream>

using namespace std;

int T, A, B;

int gcd (int n1, int n2) {
    while (n1 > 0 && n2 > 0) {
        if (n1 > n2) n1 %= n2;
        else n2 %= n1;
    }

    if (n1 == 0) return n2;
    else return n1;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;

    while (T--) {
        cin >> A >> B;

        int gcdAB = gcd(A, B);
        cout << (A * B / gcdAB) << "\n";
    }

    return 0;
}