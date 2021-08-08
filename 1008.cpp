#include <iostream>

using namespace std;

int A, B;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> A >> B;

    cout.precision(10);
    cout << (double) A / B;

    return 0;
}