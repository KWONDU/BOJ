#include <iostream>

using namespace std;

int N, M, K, A[100][100], B[100][100];

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) cin >> A[i][j];
    }
    cin >> M >> K;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) cin >> B[i][j];
    }

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < K; y++) {
            int cXY = 0;
            for (int z = 0; z < M; z++) cXY += A[x][z] * B[z][y];
            cout << cXY << " ";
        }
        cout << "\n";
    }

    return 0;
}