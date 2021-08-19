#include <iostream>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 300 + 1, INF = 5000 * 100 + 1;

int n, m, a, b, c;
int S, E, C[MAX][MAX], F[MAX][MAX], pre[MAX], maxFlow;
vector<int> V[MAX];

void input () {
    for (int i = 0; i < MAX; i++) memset(C[i], 0, sizeof(C[i]));
    for (int i = 0; i < MAX; i++) memset(C[i], 0, sizeof(C[i]));
    maxFlow = 0;
    
    cin >> n >> m;
    while (m--) {
        cin >> a >> b >> c;
        
        V[a].push_back(b);
        V[b].push_back(a);
        C[a][b] += c;
        C[b][a] += c;
    }
    S = 1, E = n;
    
    return ;
}

bool edmondKarp () {
    memset(pre, -1, sizeof(pre));
    queue<int> q;
    
    q.push(S);
    while (!q.empty() && pre[E] == -1) {
        int cur = q.front(); q.pop();
        
        for (int nxt : V[cur]) {
            if (pre[nxt] == -1 && C[cur][nxt] - F[cur][nxt] > 0) {
                pre[nxt] = cur;
                q.push(nxt);
                
                if (pre[E] != -1) break;
            }
        }
    }
    
    if (pre[E] == -1) return false;
    
    int nowFlow = INF;
    for (int i = E; i != S; i = pre[i]) nowFlow = min(nowFlow, C[pre[i]][i] - F[pre[i]][i]);
    for (int i = E; i != S; i = pre[i]) {
        F[pre[i]][i] += nowFlow;
        F[i][pre[i]] -= nowFlow;
    }
    
    maxFlow += nowFlow;
    
    return true;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    
    while (true) {
        if (!edmondKarp()) break;
    }
    
    cout << maxFlow;
    
    return 0;
}