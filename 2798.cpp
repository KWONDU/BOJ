#include <iostream>

using namespace std;

int N, M, card[100];

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> card[i];

    int sum = 0;
    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            for (int k = j + 1; k < N; k++) {
                int temp = card[i] + card[j] + card[k];
                if (sum < temp && temp <= M) sum = temp;
            }
        }
    }

    cout << sum;

    return 0;
}