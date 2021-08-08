#include <iostream>

using namespace std;

int A, B, C;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> A >> B >> C;

    int N = A * B * C;
    int cnt[10];
    for (int i = 0; i < 10; i++) cnt[i] = 0;

    while (N > 0) {
        cnt[N % 10]++;
        N /= 10;
    }

    for (int i = 0; i < 10; i++) cout << cnt[i] << "\n";

    return 0;
}