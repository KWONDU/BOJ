#include <iostream>
#include <memory.h>
#include <vector>
#include <queue>

using namespace std;

const int MAX = (1000 + 1) * 2, INF = 1000 + 1;

int N, M, S, E, c[MAX][MAX], f[MAX][MAX], pre[MAX], maxFlow;
vector<int> V[MAX];

void init () {
    for (int i = 0; i < MAX; i++) memset(c[i], 0, sizeof(c[i]));
    for (int i = 0; i < MAX; i++) memset(f[i], 0, sizeof(f[i]));
    maxFlow = 0;
    
    return ;
}

void make_edge (int p, int q, int cap) {
    V[p].push_back(q);
    V[q].push_back(p);
    c[p][q] += cap;
    
    return ;
}

void input () {
    init();
    
    int t, j;
    
    cin >> N >> M;
    
    S = 0, E = N + M + 1;
    
    for (int i = 1; i <= N; i++) make_edge(S, i, 2);
    for (int i = 1; i <= N; i++) {
        cin >> t;
        while (t--) {
            cin >> j;
            make_edge(i, N + j, 1);
        }
    }
    for (int i = N + 1; i <= N + M; i++) make_edge(i, E, 1);
    
    return ;
}

bool edmondKarp () {
    memset(pre, -1, sizeof(pre));
    queue<int> Q;
    
    Q.push(S);
    while (!Q.empty() && pre[E] == -1) {
        int cur = Q.front(); Q.pop();
        
        for (int nxt : V[cur]) {
            if (pre[nxt] == -1 && c[cur][nxt] - f[cur][nxt] > 0) {
                pre[nxt] = cur;
                Q.push(nxt);
                
                if (pre[E] != -1) break;
            }
        }
    }
    
    if (pre[E] == -1) return false;
    
    int flow = INF;
    for (int i = E; i != S; i = pre[i]) flow = min(flow, c[pre[i]][i] - f[pre[i]][i]);
    for (int i = E; i != S; i = pre[i]) {
        f[pre[i]][i] += flow;
        f[i][pre[i]] -= flow;
    }
    
    maxFlow += flow;
    
    return true;
}

int main () {ios_base::sync_with_stdio(false);cout.tie(NULL);cout.tie(NULL);
    input();
    while (edmondKarp()) {}
    cout << maxFlow;

    return 0;
}