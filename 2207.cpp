#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int MAX = 10000 * 2 + 1;

int N, M, x, y;
vector<int> v[MAX];

bool visit[MAX];
int scc[MAX], scc_num;
vector<int> v_re[MAX];
stack<int> st;

void dfs1 (int cur) {
    visit[cur] = true;
    for (int nxt : v[cur])
        if (!visit[nxt]) dfs1(nxt);
    st.push(cur);
    
    return ;
}

void dfs2 (int cur) {
    scc[cur] = scc_num;
    for (int nxt : v_re[cur])
        if (scc[nxt] == 0) dfs2(nxt);
    
    return ;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    while (N--) {
        cin >> x >> y;
        v[-x + M].push_back(y + M);
        v[-y + M].push_back(x + M);
        
        v_re[y + M].push_back(-x + M);
        v_re[x + M].push_back(-y + M);
    }
    
    for (int i = 0; i < M * 2 + 1; i++) visit[i] = false;
    for (int i = 0; i < M * 2 + 1; i++) scc[i] = 0;
    scc_num = 0;
    
    for (int i = 0; i < M * 2 + 1; i++)
        if (!visit[i]) dfs1(i);
    
    while (!st.empty()) {
        int cur = st.top();
        st.pop();
        if (scc[cur] == 0) {
            scc_num++;
            dfs2(cur);
        }
    }
    
    for (int i = 1; i <= M; i++)
        if (scc[-i + M] == scc[i + M]) {
            cout << "OTL";
            return 0;
        }
    cout << "^_^";
    
    return 0;
}