#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <queue>

using namespace std;

#define pip pair<int, pair<int, int>>

struct cmp {
    bool operator () (pip p1, pip p2) {
        return p1.first > p2.first;
    }
};

int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int m, n; cin >> m >> n;
    int road[1000][1000];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) cin >> road[i][j];
    
    bool chk[1000][1000];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) chk[i][j] = false;
    
    if (road[0][0] == -1 || road[m - 1][n - 1] == -1) {
        cout << "-1";
        return 0;
    }
    
    int ans = -1;
    priority_queue<pip, vector<pip>, cmp> pq;
    pq.push({road[0][0], {0, 0}});
    while (!pq.empty()) {
        int price = pq.top().first;
        int xpos = pq.top().second.first;
        int ypos = pq.top().second.second;
        pq.pop();
        
        if (xpos == m - 1 && ypos == n - 1) {
            ans = price;
            break;
        }
        
        if (chk[xpos][ypos]) continue;
        
        for (int i = 0; i < 4; i++) {
            int chkx = xpos + dir[i][0];
            int chky = ypos + dir[i][1];
            
            if (chkx < 0 || chkx >= m || chky < 0 || chky >= n) continue;
            if (road[chkx][chky] == -1) continue;
            if (chk[chkx][chky]) continue;
            
            pq.push({price + road[chkx][chky], {chkx, chky}});
        }
        
        chk[xpos][ypos] = true;
    }
    
    cout << ans;
    
    return 0;
}