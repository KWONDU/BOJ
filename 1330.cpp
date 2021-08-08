#include <iostream>

using namespace std;

int n1, n2;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n1 >> n2;
    if (n1 < n2)
        cout << "<";
    else if (n1 == n2)
        cout << "==";
    else
        cout << ">";

    return 0;
}