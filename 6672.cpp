#include <iostream>
#include <memory.h>
#include <utility>
#include <vector>

using namespace std;

const int MAX = 10000;

int P, C, p1, p2;
vector<int> adj[MAX];

int dfn[MAX], low[MAX], acCnt[MAX], order, netNum;

void dfs (int cur, int par = -1) {
    dfn[cur] = low[cur] = ++order;
    
    for (int nxt : adj[cur]) {
        if (nxt == par) continue;
        
        if (dfn[nxt] == 0) {
            dfs(nxt, cur);
            
            low[cur] = min(low[cur], low[nxt]);
            if (dfn[cur] <= low[nxt]) {
                acCnt[cur]++;
            }
        } else if (dfn[cur] > dfn[nxt]) {
            low[cur] = min(low[cur], dfn[nxt]);
        }
    }
    
    if (par != -1) acCnt[cur]++;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (true) {
        cin >> P >> C;
        if (P == 0 && C == 0) break;
        
        for (int i = 0; i < MAX; i++) adj[i].clear();
        
        while (C--) {
            cin >> p1 >> p2;
            adj[p1].push_back(p2);
            adj[p2].push_back(p1);
        }
        
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(acCnt));
        memset(acCnt, 0, sizeof(acCnt));
        order = 0, netNum = 0;
        
        for (int i = 0; i < P; i++) {
            if (dfn[i] == 0) {
                netNum++;
                dfs(i);
            }
        }
        
        int maxVal = 0;
        for (int i = 0; i < P; i++) maxVal = max(maxVal, acCnt[i]);
        cout << (netNum - 1) + maxVal << "\n";
    }

    return 0;
}