#include <iostream>

using namespace std;

int M, N;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> M >> N;

    int sum = 0, minVal = N;
    for (int i = M; i <= N; i++) {
        int j = 2;
        bool chk = true;
        while (j * j <= i) {
            if (i % j == 0) {
                chk = false;
                break;
            }
            j++;
        }

        if (chk && i != 1) {
            sum += i;
            minVal = min(minVal, i);
        }
    }

    if (sum == 0) cout << "-1";
    else cout << sum << "\n" << minVal;

    return 0;
}