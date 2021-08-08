#include <iostream>

using namespace std;

int num, x = 0;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 0; i < 5; i++) {
        cin >> num;
        x += num * num;
    }

    cout << (x % 10);

    return 0;
}