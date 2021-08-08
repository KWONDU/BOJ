#include <iostream>

using namespace std;

int N, score[1000], sum = 0;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> score[i];
        sum += score[i];
    }

    int maxScore = score[0];
    for (int i = 1; i < N; i++) maxScore = max(maxScore, score[i]);

    double avg = (double)sum / N;
    cout << (avg / maxScore * 100);
    
    return 0;
}