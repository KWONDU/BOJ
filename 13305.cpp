#include <iostream>

using namespace std;

int N, len[100000 - 1], price[100000];

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N - 1; i++) cin >> len[i];
    for (int i = 0; i < N; i++) cin >> price[i];

    long long int minVal = 0;
    minVal += (long long int)price[0] * len[0];
    int p = price[0];
    for (int i = 1; i <= N - 2; i++) {
        if (p > price[i]) p = price[i];
        minVal += (long long int)p * len[i];
    }

    cout << minVal;

    return 0;
}