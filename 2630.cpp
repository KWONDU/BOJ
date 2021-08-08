#include <iostream>

using namespace std;

int paper[128][128];

int whiteCnt;
int blueCnt;

bool whiteChk (int startX, int startY, int endX, int endY) {
    for (int i = startX; i <= endX; i++)
        for (int j = startY; j <= endY; j++)
            if (paper[i][j] == 1) return false;
    return true;
}

bool blueChk (int startX, int startY, int endX, int endY) {
    for (int i = startX; i <= endX; i++)
        for (int j = startY; j <= endY; j++)
            if (paper[i][j] == 0) return false;
    return true;
}

void cnt (int x1, int y1, int x2, int y2) {
    if (x2 - x1 != y2 - y1) return;
    
    if (whiteChk(x1, y1, x2, y2)) {
        whiteCnt++;
        return;
    } else if (blueChk(x1, y1, x2, y2)) {
        blueCnt++;
        return;
    }
    
    cnt(x1, y1, (x1 + x2) / 2, (y1 + y2) / 2);
    cnt(x1, (y1 + y2) / 2 + 1, (x1 + x2) / 2, y2);
    cnt((x1 + x2) / 2 + 1, y1, x2, (y1 + y2) / 2);
    cnt((x1 + x2) / 2 + 1, (y1 + y2) / 2 + 1, x2, y2);
}

int main()
{
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            paper[i][j] = temp;
        }
    
    whiteCnt = 0;
    blueCnt = 0;
    
    cnt(0, 0, n - 1, n - 1);
    
    cout << whiteCnt << "\n" << blueCnt;
    
    return 0;
}