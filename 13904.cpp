#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    int homework[1000][1000 + 1] = {0};
    int tempd, tempw;
    for (int i = 0; i < n; i++) {
        cin >> tempd >> tempw;
        homework[i][0] = tempw;
        for (int j = 1; j <= tempd; j++)
            homework[i][j] = 1;
    }
    
    int maxsum = 0;
    int tempmax = 0;
    int pos = -1;
    for (int i = 1000; i >= 1; i--) {
        for (int j = 0; j < n; j++)
            if (homework[j][i] == 1 && tempmax < homework[j][0]) {
                tempmax = homework[j][0];
                pos = j;
            }
        if (pos != -1) {
            for (int j = 1; j <= 1000; j++)
                homework[pos][j] = 0;
        }
        maxsum += tempmax;
        tempmax = 0; pos = -1;
    }
    
    cout << maxsum;
}