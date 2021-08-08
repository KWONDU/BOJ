#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int scc[5000 + 1];
int n, m;

int node_num, scc_num;
stack<int> st;
int dfn[5000 + 1];
int low[5000 + 1];
bool finish[5000 + 1];

void dfs (vector<int> v[], int cur) {
    dfn[cur] = low[cur] = ++node_num;
    st.push(cur);
    
    for (int nxt: v[cur]) {
        if (dfn[nxt] == 0) {
            dfs(v, nxt);
            low[cur] = min(low[cur], low[nxt]);
        } else if (!finish[nxt]) {
            low[cur] = min(low[cur], dfn[nxt]);
        }
    }
    
    if (dfn[cur] == low[cur]) {
        scc_num++;
        
        while (true) {
            int elem = st.top();
            st.pop();
            scc[elem] = scc_num;
            finish[elem] = true;
            if (cur == elem) break;
        }
    }
    
    return;
}

void tarjan (vector<int> v[]) {
    for (int i = 1; i <= n; i++) {
        scc[i] = 0;
        dfn[i] = 0;
        low[i] = 0;
        finish[i] = false;
    }
    
    node_num = 0, scc_num = 0;
    for (int i = 1; i <= n; i++)
        if (!finish[i]) dfs(v, i);
    
    return;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    while (true) {
        cin >> n >> m;
        if (n == 0) break;
        
        vector<int> graph[5000 + 1];
        while (m--) {
            int v, w;
            cin >> v >> w;
            graph[v].push_back(w);
        }
        
        tarjan(graph);
        
        bool chk[5000 + 1];
        for (int i = 1; i <= scc_num; i++) chk[i] = true;
        for (int i = 1; i <= n; i++) {
            if (!chk[scc[i]]) continue;
            for (int j : graph[i]) {
                if (scc[i] != scc[j]) {
                    chk[scc[i]] = false;
                    break;
                }
            }
        }
        
        for (int i = 1; i <= n; i++)
            if (chk[scc[i]]) cout << i << " ";
        cout << "\n";
    }
    
    return 0;
}