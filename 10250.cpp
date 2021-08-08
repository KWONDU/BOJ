#include <iostream>

using namespace std;

int T, H, W, N;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;

    while (T--) {
        cin >> H >> W >> N;

        cout << (100 * (N - (N - 1) / H * H) + ((N - 1) / H + 1)) << "\n";
    }

    return 0;
}