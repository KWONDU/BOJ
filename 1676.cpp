#include <iostream>

using namespace std;

int N;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (i % 5 == 0) {
            int temp = i;
            while (temp % 5 == 0) {
                cnt++;
                temp /= 5;
            }
        }
    }

    cout << cnt;

    return 0;
}