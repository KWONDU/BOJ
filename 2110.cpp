#include <iostream>
#include <algorithm>

using namespace std;

int N, C, x[200000];

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> C;
    for (int i = 0; i < N; i++) cin >> x[i];

    sort(x, x + N);

    int l = 1, r = x[N - 1] - x[0], m, ans = 0;
    while (l <= r) {
        m = (l + r) / 2;
        int start = x[0], cnt = 1;
        for (int i = 1; i < N; i++) {
            if (x[i] - start >= m) {
                cnt++;
                start = x[i];
            }
        }

        if (cnt >= C) {
            ans = m;
            l = m + 1;
        } else r = m - 1;
    }

    cout << ans;

    return 0;
}