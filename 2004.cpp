#include <iostream>

using namespace std;

int N, M;

int cnt2 (int n) {
    int cnt = 0;
    long long int i = 2;
    while (i <= n) {
        cnt += (n / i);
        i *= 2;
    }
    return cnt;
}

int cnt5 (int n) {
    int cnt = 0;
    long long int i = 5;
    while (i <= n) {
        cnt += (n / i);
        i *= 5;
    }
    return cnt;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    cout << min(cnt2(N) - cnt2(M) - cnt2(N - M), cnt5(N) - cnt5(M) - cnt5(N - M));

    return 0;
}