#include <iostream>

using namespace std;

int n, fib[20 + 1];

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;

    fib[0] = 0, fib[1] = 1;
    for (int i = 2; i <= n; i++) fib[i] = fib[i - 1] + fib[i - 2];

    cout << fib[n];

    return 0;
}