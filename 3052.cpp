#include <iostream>

using namespace std;

int num[10];

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 0; i < 10; i++) cin >> num[i];

    int cnt = 0;
    bool re[42];
    for (int i = 0; i < 42; i++) re[i] = false;

    for (int i = 0; i < 10; i++) {
        if (!re[num[i] % 42]) {
            re[num[i] % 42] = true;
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}