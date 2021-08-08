#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int tomato[1000][1000];
queue<pair<pair<int, int>, int>> q;

int main()
{
    int m, n;
    cin >> m >> n;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int state;
            cin >> state;
            tomato[i][j] = state;
            
            if (state == 1) q.push(make_pair(make_pair(i, j), 0));
        }
    
    int day = 0;
    while (!q.empty()) {
        pair<pair<int, int>, int> p = q.front();
        int x = p.first.first;
        int y = p.first.second;
        day = p.second;
        q.pop();
        
        if (x > 0 && tomato[x - 1][y] == 0) {
            tomato[x - 1][y] = 1;
            q.push(make_pair(make_pair(x - 1, y), day + 1));
        } if (x < n - 1 && tomato[x + 1][y] == 0) {
            tomato[x + 1][y] = 1;
            q.push(make_pair(make_pair(x + 1, y), day + 1));
        } if (y > 0 && tomato[x][y - 1] == 0) {
            tomato[x][y - 1] = 1;
            q.push(make_pair(make_pair(x, y - 1), day + 1));
        } if (y < m - 1 && tomato[x][y + 1] == 0) {
            tomato[x][y + 1] = 1;
            q.push(make_pair(make_pair(x, y + 1), day + 1));
        }
    }
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (tomato[i][j] == 0) {
                cout << "-1";
                return 0;
            }
    
    cout << day;
    
    return 0;
}