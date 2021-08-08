#include <iostream>

using namespace std;

int N, first, nxt;

int gcd (int n1, int n2) {
    while (n1 > 0 && n2 > 0) {
        if (n1 > n2) n1 %= n2;
        else n2 %= n1;
    }

    if (n1 == 0) return n2;
    else return n1;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    cin >> first;
    for (int i = 1; i < N; i++) {
        cin >> nxt;
        cout << (first / gcd(first, nxt)) << "/" << (nxt / gcd(first, nxt)) << "\n";
    }

    return 0;
}