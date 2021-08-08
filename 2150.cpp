#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> graph[10000 + 1];

bool visit[10000 + 1];
vector<int> graph_reverse[10000 + 1];
int scc[10000 + 1], num_scc;
stack<int> st;

int V, E;

void dfs1 (int cur) {
    visit[cur] = true;
    for (int nxt: graph[cur])
        if (!visit[nxt]) dfs1(nxt);
    st.push(cur);
    
    return;
}

void dfs2 (int cur) {
    scc[cur] = num_scc;
    for (int nxt: graph_reverse[cur])
        if (scc[nxt] == 0) dfs2(nxt);
    
    return;
}

void kosaraju () {
    while (!st.empty()) {
        int cur = st.top();
        st.pop();
        if (scc[cur] > 0) continue;
        num_scc++;
        dfs2(cur);
    }
    
    return;
}

bool comp (pair<int, int> p1, pair<int, int> p2) {
    return p1.first < p2.first ? true : false;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> V >> E;
    while (E--) {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
        graph_reverse[B].push_back(A);
    }
    
    for (int i = 1; i <= V; i++) visit[i] = false;
    for (int i = 1; i <= V; i++) scc[i] = 0;
    num_scc = 0;
    
    for (int i = 1; i <= V; i++)
        if (!visit[i]) dfs1(i);
    
    kosaraju();
    
    cout << num_scc << "\n";
    vector<int> v_scc[10000 + 1];
    for (int i = 1; i <= V; i++) v_scc[scc[i]].push_back(i);
    
    vector<pair<int, int>> temp;
    for (int i = 1; i <= num_scc; i++) temp.push_back(make_pair(v_scc[i][0], i));
    sort (temp.begin(), temp.end(), comp);
    
    for (auto i : temp) {
        for (int j : v_scc[i.second]) cout << j << " ";
        cout << "-1\n";
    }
    
    return 0;
}