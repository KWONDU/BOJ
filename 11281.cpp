#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int MAX = 10000 * 2 + 1;

int N, M, xi, xj;
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
    while (M--) {
        cin >> xi >> xj;
        v[-xi + N].push_back(xj + N);
        v[-xj + N].push_back(xi + N);
        
        v_re[xj + N].push_back(-xi + N);
        v_re[xi + N].push_back(-xj + N);
    }
    
    for (int i = 0; i < N * 2 + 1; i++) visit[i] = false;
    for (int i = 0; i < N * 2 + 1; i++) scc[i] = 0;
    scc_num = 0;
    
    for (int i = 0; i < N * 2 + 1; i++)
        if (!visit[i]) dfs1(i);
    
    while (!st.empty()) {
        int cur = st.top();
        st.pop();
        if (scc[cur] == 0) {
            scc_num++;
            dfs2(cur);
        }
    }
    
    for (int i = 0; i < N; i++)
        if (scc[i] == scc[N * 2 - i]) {
            cout << "0";
            return 0;
        }
    
    cout << "1\n";
    for (int i = N - 1; i >= 0; i--) {
        if (scc[i] > scc[N * 2 - i]) cout << "0 ";  // x : false -> not_x : true
        else cout << "1 ";  // not_x : false -> x : true
    }
    // for (int i = 1; i <= N; i++) {
    //     if (scc[-i + N] > scc[i + N]) cout << "0 ";
    //     else cout << "1 ";
    // }
    
    return 0;
}