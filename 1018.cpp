#include <iostream>

using namespace std;

int N, M;
char board[50][50 + 1];

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    for (int i = 0; i < N; i++) cin >> board[i];

    int minVal = 64;
    for (int i = 0; i < N - 7; i++)
        for (int j = 0; j < M - 7; j++) {
            int cnt = 0;
            for (int x = 0; x < 8; x++)
                for (int y = 0; y < 8; y++) {
                    if (x % 2 == y % 2 && board[i + x][j + y] != 'W')
                        cnt++;
                    else if (x % 2 != y % 2 && board[i + x][j + y] != 'B')
                        cnt++;
                }
            if (cnt > 32)
                cnt = 64 - cnt;
            
            if (cnt < minVal)
                minVal = cnt;
        }
    
    cout << minVal;

    return 0;
}