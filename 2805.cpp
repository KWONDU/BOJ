#include <iostream>
#include <algorithm>

using namespace std;

int N, M, forest[1000000];

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> forest[i];

    sort(forest, forest + N);

    long h = 0, l = 0, r = forest[N - 1];
    while (l <= r) {
        long m = (l + r) / 2, len = 0;
        for (int i = 0; i < N; i++) {
            if (forest[i] > m) len += (forest[i] - m);
        }

        if (len < M) r = m - 1;
        else {
            if (m > h) h = m;
            l = m + 1;
        }
    }

    cout << h;

    return 0;
}