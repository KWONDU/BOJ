#include <iostream>
#include <algorithm>

using namespace std;

int N, A[1000];

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];

    int frontLen[1000];
    frontLen[0] = 1;
    for (int i = 1; i < N; i++) {
        frontLen[i] = 1;
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i]) {
                frontLen[i] = max(frontLen[i], frontLen[j] + 1);
            }
        }
    }

    int b[1000];
    for (int i = 0; i < N; i++) b[i] = A[N - 1 - i];

    int backLen[1000];
    backLen[0] = 1;
    for (int i = 1; i < N; i++) {
        backLen[i] = 1;
        for (int j = 0; j < i; j++) {
            if (b[j] < b[i]) {
                backLen[i] = max(backLen[i], backLen[j] + 1);
            }
        }
    }

    int len[1000];
    for (int i = 0; i < N; i++) len[i] = frontLen[i] + backLen[N - 1 - i];
    sort(len, len + N);

    cout << len[N - 1] - 1;

    return 0;
}