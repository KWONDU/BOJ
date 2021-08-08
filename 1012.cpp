#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int m, n, k;
        cin >> m >> n >> k;
        
        bool field[50][50];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) field[i][j] = false;
        
        while (k--) {
            int x, y;
            cin >> x >> y;
            field[x][y] = true;
        }
        
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(!field[i][j]) continue;
                
                cnt++;
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                field[i][j] = false;
                while (!q.empty()) {
                    pair<int, int> pos = q.front();
                    int posx = pos.first;
                    int posy = pos.second;
                    q.pop();
                    
                    if (posx > 0 && field[posx - 1][posy]) {
                        q.push(make_pair(posx - 1, posy));
                        field[posx - 1][posy] = false;
                    } if (posx < m - 1 && field[posx + 1][posy]) {
                        q.push(make_pair(posx + 1, posy));
                        field[posx + 1][posy] = false;
                    } if (posy > 0 && field[posx][posy - 1]) {
                        q.push(make_pair(posx, posy - 1));
                        field[posx][posy - 1] = false;
                    } if (posy < n - 1 && field[posx][posy + 1]) {
                        q.push(make_pair(posx, posy + 1));
                        field[posx][posy + 1] = false;
                    }
                }
            }
        }
        
        cout << cnt << "\n";
    }
    
    return 0;
}