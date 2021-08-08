#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n, m, b;
    cin >> n >> m >> b;
    int world[500][500];
    int minheight = 257, maxheight = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> world[i][j];
            if (world[i][j] < minheight)
                minheight = world[i][j];
            if (world[i][j] > maxheight)
                maxheight = world[i][j];
        }
    
    int anstime = 128000001, ansheight = -1;
    for (int h = minheight; h <= maxheight; h++) {
        int minus = 0, plus = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                int temp = world[i][j] - h;
                if (temp > 0)
                    plus += temp;
                else
                    minus += (0 - temp);
            }
        
        if (plus + b < minus)
            continue;
        
        int temptime = plus * 2 + minus;
        if (temptime <= anstime) {
            anstime = temptime;
            ansheight = h;
        }
    }
    
    cout << anstime << " " << ansheight;
}