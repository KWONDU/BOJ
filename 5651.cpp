#include <iostream>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 300 + 1, INF = 20000 + 1;

int K, N, M, f, t, b, source, sink;
int C[MAX][MAX], F[MAX][MAX], pre[MAX], maxFlow;
vector<int> V[MAX];
vector<pair<int, int>> edge;

void input () {
    for (int i = 0; i < MAX; i++) memset(C[i], 0, sizeof(C[i]));
    for (int i = 0; i < MAX; i++) memset(F[i], 0, sizeof(F[i]));
    for (int i = 0; i < MAX; i++) V[i].clear();
    edge.clear(), maxFlow = 0;
    
    cin >> N >> M;
    while (M--) {
        cin >> f >> t >> b;
        
        V[f].push_back(t);
        V[t].push_back(f);
        C[f][t] += b;
        
        edge.push_back(make_pair(f, t));
    }
    source = 1, sink = N;
    
    return ;
}

bool edmondKarp (bool flag) {
    memset(pre, -1, sizeof(pre));
    queue<int> q;
    
    q.push(source);
    while (!q.empty() && pre[sink] == -1) {
        int cur = q.front(); q.pop();
        
        for (int nxt : V[cur]) {
            if (pre[nxt] == -1 && C[cur][nxt] - F[cur][nxt] > 0) {
                pre[nxt] = cur;
                q.push(nxt);
                
                if (pre[sink] != -1) break;
            }
        }
    }
    
    if (flag) {
        if (pre[sink] == -1) return true;
        else return false;
    }
    
    if (pre[sink] == -1) return false;
    
    int nowFlow = INF;
    for (int i = sink; i != source; i = pre[i]) nowFlow = min(nowFlow, C[pre[i]][i] - F[pre[i]][i]);
    for (int i = sink; i != source; i = pre[i]) {
        F[pre[i]][i] += nowFlow;
        F[i][pre[i]] -= nowFlow;
    }
    
    maxFlow += nowFlow;
    
    return true;
}

bool edmondKarp (pair<int, int> p) {
    source = p.first, sink = p.second;
    return edmondKarp(true);
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> K;
    while (K--) {
        input();
        
        while (true) {
            if (!edmondKarp(false)) break;
        }
        
        int cnt = 0;
        for (auto e : edge) {
            if (edmondKarp(e)) cnt ++;
        }
        
        cout << cnt << "\n";
    }
    
    return 0;
}