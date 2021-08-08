#include <iostream>

using namespace std;

int N, bmi[50][2];

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> bmi[i][0] >> bmi[i][1];

    int rank[50];
    for (int i = 0; i < 50; i++) rank[i] = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (bmi[i][0] > bmi[j][0] && bmi[i][1] > bmi[j][1]) rank[j]++;
            else if (bmi[i][0] < bmi[j][0] && bmi[i][1] < bmi[j][1]) rank[i]++;
        }
    }

    for (int i = 0; i < N; i++) cout << (rank[i] + 1) << " ";

    return 0;
}