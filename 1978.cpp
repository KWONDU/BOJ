#include <iostream>

using namespace std;

int N, i;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    int cnt = 0;
    while (N--) {
        cin >> i;

        bool chk = false;
        int j = 2;
        while (j * j <= i) {
            if (i % j == 0) chk = true;
            j++;
        }

        if (!chk && i != 1) cnt++;
    }

    cout << cnt;

    return 0;
}