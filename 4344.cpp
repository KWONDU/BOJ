#include <iostream>

using namespace std;

int C, N;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> C;

    while (C--) {
        cin >> N;
        int score[1000];
        for (int i = 0; i < N; i++) cin >> score[i];

        int sum = 0;
        for (int i = 0; i < N; i++) sum += score[i];
        double avg = (double)sum / N;

        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (avg < score[i]) cnt++;
        }

        cout << fixed;
        cout.precision(3);
        cout << (double)cnt / N * 100 << "%\n";
    }

    return 0;
}