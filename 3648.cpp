#include <iostream>
#include <memory.h>
#include <vector>
#include <stack>

using namespace std;

const int MAXLEN = 1000 * 2 + 1;

int n, m, a, b;
vector<int> v[MAXLEN];

bool visit[MAXLEN];
int scc[MAXLEN], sccNum;
vector<int> vRe[MAXLEN];
stack<int> st;

void dfs1 (int cur) {
    visit[cur] = true;
    for (int nxt : v[cur])
        if (!visit[nxt]) dfs1(nxt);
    st.push(cur);
    
    return ;
}

void dfs2 (int cur) {
    scc[cur] = sccNum;
    for (int nxt : vRe[cur])
        if (scc[nxt] == 0) dfs2(nxt);
    
    return ;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (true) {
        cin >> n >> m;
        if (cin.eof()) break;
        for (int i = 0; i < MAXLEN; i++) v[i].clear();
        for (int i = 0; i < MAXLEN; i++) vRe[i].clear();
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            v[-a + n].push_back(b + n);
            v[-b + n].push_back(a + n);
            
            vRe[b + n].push_back(-a + n);
            vRe[a + n].push_back(-b + n);
        }
        
        v[-1 + n].push_back(1 + n);
        vRe[1 + n].push_back(-1 + n);
        
        memset(visit, false, sizeof(visit));
        memset(scc, 0, sizeof(scc));
        sccNum = 0;
        
        for (int i = 0; i < n * 2 + 1; i++)
            if (!visit[i]) dfs1(i);
        
        while (!st.empty()) {
            int cur = st.top();
            st.pop();
            if (scc[cur] == 0) {
                sccNum++;
                dfs2(cur);
            }
        }
        
        if (scc[-1 + n] > scc[1 + n]) {
            cout << "no\n";
        } else {
            bool flag = true;
            for (int i = 2; i <= n; i++) {
                if (scc[-i + n] == scc[i + n]) {
                    cout << "no\n";
                    flag = false;
                    break;
                }
            }
            if (flag) cout << "yes\n";
        }
    }
    
    return 0;
}