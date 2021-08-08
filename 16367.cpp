#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int MAX = 5000 * 2 + 1;

int k, n, l[3];
char c[3];
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
    cin >> k >> n;
    while (n--) {
        for (int i = 0; i < 3; i++) cin >> l[i] >> c[i];
        for (int i = 0; i < 3; i++)
            if (c[i] == 'B') l[i] = -l[i];
        
        for (int i = 0; i < 3; i++) {
            v[-l[i] + k].push_back(l[(i + 1) % 3] + k);
            v[-l[(i + 1) % 3] + k].push_back(l[i] + k);
            
            v_re[l[(i + 1) % 3] + k].push_back(-l[i] + k);
            v_re[l[i] + k].push_back(-l[(i + 1) % 3] + k);
        }
    }
    
    for (int i = 0; i < k * 2 + 1; i++) visit[i] = false;
    for (int i = 0; i < k * 2 + 1; i++) scc[i] = 0;
    scc_num = 0;
    
    for (int i = 0; i < k * 2 + 1; i++)
        if (!visit[i]) dfs1(i);
    
    while (!st.empty()) {
        int cur = st.top();
        st.pop();
        if (scc[cur] == 0) {
            scc_num++;
            dfs2(cur);
        }
    }
    
    for (int i = 1; i <= k; i++)
        if (scc[-i + k] == scc[i + k]) {
            cout << "-1";
            return 0;
        }
    
    for (int i = 1; i <= k; i++) {
        if (scc[-i + k] > scc[i + k]) cout << "B";
        else cout << "R";
    }
    
    return 0;
}