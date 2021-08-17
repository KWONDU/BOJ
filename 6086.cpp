#include <iostream>
#include <memory.h>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 52, INF = 1000 + 1;

int ctoi (char c) {
    if ((int)c < (int)'a') return (c - 'A');
    else return (c - 'a' + 26);
}

int N, S = ctoi('A'), E = ctoi('Z'), c[MAX][MAX], f[MAX][MAX], pre[MAX];
vector<int> V[MAX];

void input () {
    char x, y;
    int z;
    
    for (int i = 0; i < MAX; i++) memset(c[i], 0, sizeof(c[i]));
    for (int i = 0; i < MAX; i++) memset(f[i], 0, sizeof(f[i]));
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x >> y >> z;
        int from = ctoi(x), to = ctoi(y);
        V[from].push_back(to);
        V[to].push_back(from);
        c[from][to] += z;
        c[to][from] += z;
    }
    
    return ;
}

void bfs () {
    memset(pre, -1, sizeof(pre));
    
    queue<int> q;
    q.push(S);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (int nxt : V[cur]) {
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
        if (pre[E] == -1) break;
        int now = INF;
        for (int i = E; i != S; i = pre[i]) now = min(now, c[pre[i]][i] - f[pre[i]][i]);
        for (int i = E; i != S; i = pre[i]) {
            f[pre[i]][i] += now;
            f[i][pre[i]] -= now;
        }
    }
    
    int ans = 0;
    for (int j = 0; j < MAX; j++) ans += f[j][E];
    cout << ans;
    
    return 0;
}