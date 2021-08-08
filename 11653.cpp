#include <iostream>

using namespace std;

int N;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    int temp = N;
    for (int i = 2; i * i <= N; i++) {
        if (temp == 1) break;

        while (temp > 1 && temp % i == 0) {
            temp /= i;
            cout << i << "\n";
        }
    }

    if (temp > 1) cout << temp;

    return 0;
}