#include <iostream>

using namespace std;

int N;
int paper[2187][2187];

int cnt[3];

void cal (int x, int y, int len) {
    int chk = true;
    for (int i = x; i < x + len; i++)
        for (int j = y; j < y + len; j++)
            if (paper[i][j] != paper[x][y]) {
                chk = false;
                break;
            }
    if (chk) {
        cnt[paper[x][y] + 1]++;
    }
    else {
        int partLen = len / 3;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                cal(x + i * partLen, y + j * partLen, partLen);
    }
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) cin >> paper[i][j];
    
    for (int i = 0; i < 3; i++) cnt[i] = 0;
    cal(0, 0, N);
    for (int i = 0; i < 3; i++) cout << cnt[i] << endl;
    
    return 0;
}