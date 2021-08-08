#include <iostream>
#include <memory.h>
#include <vector>
#include <stack>

using namespace std;

const int MAX = 100000 * 2 + 1;

int N, M, K, num, S1, S2;
vector<int> init[MAX / 2 + 1];
vector<int> v[MAX];

bool visit[MAX];
int scc[MAX], sccNum;
vector<int> vRe[MAX];
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
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> num;
        init[i].push_back(num);
    }
    for (int i = 1; i <= M; i++) {
        cin >> K;
        while (K--) {
            cin >> num;
            init[num].push_back(i);
        }
    }
    
    // 닫힌 상태 (0) 인 경우 (true, false) or (false, true)
    // (S1 | S2) & (!S1 | !S2)
    // 열린 상태 (1) 인 경우 (true, true) or (false, false)
    // (S1 | !S2) & (!S1 | S2)
    for (int i = 1; i <= N; i++) {
        S1 = init[i][1], S2 = init[i][2];
        if (init[i][0] == 0) {
            v[-S1 + M].push_back(S2 + M);
            v[-S2 + M].push_back(S1 + M);
            
            vRe[S2 + M].push_back(-S1 + M);
            vRe[S1 + M].push_back(-S2 + M);
            
            v[S1 + M].push_back(-S2 + M);
            v[S2 + M].push_back(-S1 + M);
            
            vRe[-S2 + M].push_back(S1 + M);
            vRe[-S1 + M].push_back(S2 + M);
        } else {
            v[-S1 + M].push_back(-S2 + M);
            v[S2 + M].push_back(S1 + M);
             
            vRe[-S2 + M].push_back(-S1 + M);
            vRe[S1 + M].push_back(S2 + M);
            
            v[S1 + M].push_back(S2 + M);
            v[-S2 + M].push_back(-S1 + M);
            
            vRe[S2 + M].push_back(S1 + M);
            vRe[-S1 + M].push_back(-S2 + M);
        }
    }
    
    memset(visit, false, sizeof(visit));
    memset(scc, 0, sizeof(scc));
    sccNum = 0;
    
    for (int i = 0; i < M * 2 + 1; i++)
        if (!visit[i]) dfs1(i);
    
    while (!st.empty()) {
        int cur = st.top();
        st.pop();
        if (scc[cur] == 0) {
            sccNum++;
            dfs2(cur);
        }
    }
    
    for (int i = 1; i <= M; i++)
        if (scc[-i + M] == scc[i + M]) {
            cout << "0";
            return 0;
        }
    cout << "1";
    
    return 0;
}