#include <iostream>

using namespace std;

int n1, n2;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n1 >> n2;
    cout << (n1 * (n2 % 10)) << "\n";
    cout << (n1 * ((n2 / 10) % 10)) << "\n";
    cout << (n1 * (n2 / 100)) << "\n";
    cout << (n1 * n2);

    return 0;
}