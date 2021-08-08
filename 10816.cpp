#include <iostream>
#include <algorithm>

using namespace std;

int N, M, have[500000], chk[500000];

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> have[i];
    cin >> M;
    for (int i = 0; i < M; i++) cin >> chk[i];

    sort(have, have + N);

    for (int i = 0; i < M; i++) {
        int l = 0, r = N - 1, m;
        while (l <= r) {
            m = (l + r) / 2;
            if (chk[i] > have[m]) l = m + 1;
            else r = m - 1;
        }
        int minVal = l;

        l = minVal, r = N - 1;
        while (l <= r) {
            m = (l + r) / 2;
            if (chk[i] >= have[m]) l = m + 1;
            else r = m - 1;
        }
        int maxVal = r;

        cout << (maxVal - minVal + 1) << " ";
    }

    return 0;
}