#include <iostream>
#include <memory.h>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 400 + 1;

int N, P, s = 1, e = 2, c[MAX][MAX], f[MAX][MAX], pre[MAX];
vector<int> v[MAX];

void input () {
    int a, b;
    
    for (int i = 0; i < MAX; i++) memset(c[i], 0, sizeof(c[i]));
    for (int i = 0; i < MAX; i++) memset(f[i], 0, sizeof(f[i]));
    
    cin >> N >> P;
    while (P--) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        c[a][b] = 1;
    }
    
    return ;
}

void bfs () {
    memset(pre, -1, sizeof(pre));
    
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (int nxt : v[cur]) {
            if (pre[nxt] == -1 && c[cur][nxt] - f[cur][nxt] > 0) {
                pre[nxt] = cur;
                q.push(nxt);
            }
        }
    }
    
    return ;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    
    while (true) {
        bfs();
        if (pre[e] == -1) break;
        
        for (int i = e; i != s; i = pre[i]) {
            f[pre[i]][i] ++;
            f[i][pre[i]] --;
        }
    }
    
    int ans = 0;
    for (int j = 0; j < MAX; j++) ans += f[j][e];
    cout << ans;
    
    return 0;
}