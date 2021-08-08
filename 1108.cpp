#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <queue>

using namespace std;

const int MAXLEN = 50 * 50;

map<string, int> m;
int webCount;

vector<int> link[MAXLEN];

// input variable
int N, nameCount;
string nameFrom, nameTo;

// kosaraju's variable
vector<int> linkR[MAXLEN];
bool visit[MAXLEN];
int scc[MAXLEN], sccCount;
stack<int> st;

void dfs1 (int cur) {
    visit[cur] = true;
    for (int nxt : link[cur])
        if (!visit[nxt]) dfs1(nxt);
    st.push(cur);
    
    return;
}

void dfs2 (int cur) {
    scc[cur] = sccCount;
    for (int nxt : linkR[cur])
        if (scc[nxt] == 0) dfs2(nxt);
    
    return;
}

// topological sort * SCC DAG *
vector<int> linkSCC[MAXLEN], sccOrder;
int cnt[MAXLEN];
queue<int> q;

// score calculate
long long int score[MAXLEN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    webCount = 0;
    
    // input
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> nameTo >> nameCount;
        if (m.find(nameTo) == m.end()) m.insert(make_pair(nameTo, webCount++));
        for (int j = 0; j < nameCount; j++) {
            cin >> nameFrom;
            if (m.find(nameFrom) == m.end()) m.insert(make_pair(nameFrom, webCount++));
            link[m[nameFrom]].push_back(m[nameTo]);
            linkR[m[nameTo]].push_back(m[nameFrom]);
        }
    }
    
    // kosaraju's algorithm
    for (int i = 0; i < m.size(); i++) visit[i] = false;
    for (int i = 0; i < m.size(); i++) scc[i] = 0;
    sccCount = 0;
    
    for (int i = 0; i < m.size(); i++)
        if (!visit[i]) dfs1(i);
    
    while (!st.empty()) {
        int target = st.top();
        st.pop();
        if (scc[target] == 0) {
            sccCount++;
            dfs2(target);
        }
    }
    
    // topological sort * SCC DAG *
    for (int i = 0; i < sccCount; i++) cnt[i] = 0;
    for (int i = 0; i < MAXLEN; i++) {
        for (int j : link[i]) {
            if (scc[i] == scc[j]) continue;
            
            linkSCC[scc[i]].push_back(scc[j]);
            cnt[scc[j]]++;
        }
    }
    
    for (int i = 0; i < sccCount; i++)
        if (cnt[i] == 0) q.push(i);
    
    while (!q.empty()) {
        int target = q.front();
        q.pop();
        sccOrder.push_back(target);
        
        for (int nxtTarget : linkSCC[target])
            if (--cnt[nxtTarget] == 0) q.push(nxtTarget);
    }
    
    // score calculate
    for (int i = 0; i < m.size(); i++) score[i] = 1;
    for (int i : sccOrder) {
        for (int j = 0; j < m.size(); j++) {
            if (i == scc[j]) {
                for (int k : link[j])
                    if (scc[j] != scc[k]) score[k] += score[j];
            }
        }
    }
    
    string nameAns;
    cin >> nameAns;
    if (m.find(nameAns) == m.end()) cout << "1";
    else cout << score[m[nameAns]];
    
    return 0;
}