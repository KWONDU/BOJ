#include <iostream>

using namespace std;

int N;
int matrix[1024][1024];

int pooling (int x, int y, int len) {
    if (len == 1) return matrix[x][y];
    
    int comp[4];
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) comp[i * 2 + j] = pooling(x + i * (len / 2), y + j * (len / 2), len / 2);
    
    int first = -10001, second = -10001;
    for (int i = 0; i < 4; i++) {
        if (comp[i] > first) {
            second = first;
            first = comp[i];
        } else if (second < comp[i]) second = comp[i];
    }
    
    return second;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) cin >> matrix[i][j];
    
    cout << pooling(0, 0, N);
    
    return 0;
}