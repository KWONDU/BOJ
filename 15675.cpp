#include <iostream>
#include <memory.h>
#include <vector>
#include <stack>
#include <string>

using namespace std;

const int MAX = (1000 + 1000) * 2 + 1;

int N, M, jCnt, lCnt;
string temp;
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
    jCnt = 0, lCnt = 0;

    cin >> N >> M;
    // 1 ~ N N+1 ~ N+M
    // 위치추적기가 있는 행(열)을 방문할 경우, 다시 열(행)을 방문해야 한다
    // (true, true), (false, false)
    // (!1 | 2) & (1 | !2) => 위치추적기는 고려하지 않아도 된다 false, false
    // 보석이 있는 행(열)을 방문할 경우, 다시는 행(열)을 방문하지 못한다
    // (true, false), (false, true)
    // (1 | 2) & (!1 | !2) => 모든 보석은 다 고려해야 된다
    for (int i = 1; i <= N; i++) {
        cin >> temp;
        for (int j = N + 1; j <= N + M; j++) {
            if (temp[j - N - 1] == '#') {
                v[i +  N + M].push_back(j + N + M);
                v[-j + N + M].push_back(-i + N + M);
                
                vRe[j + N + M].push_back(i + N + M);
                vRe[-i + N + M].push_back(-j + N + M);
                
                v[-i + N + M].push_back(-j + N + M);
                v[j + N + M].push_back(i + N + M);
                
                vRe[-j + N + M].push_back(-i + N + M);
                v[i + N + M].push_back(j + N + M);
            } else if (temp[j - N - 1] == '*') {
                v[-i + N + M].push_back(j + N + M);
                v[-j + N + M].push_back(i + N + M);
                
                vRe[j + N + M].push_back(-i + N + M);
                vRe[i + N + M].push_back(-j + N + M);
                
                v[i + N + M].push_back(-j + N + M);
                v[j + N + M].push_back(-i + N + M);
                
                vRe[-j + N + M].push_back(i + N + M);
                vRe[-i + N + M].push_back(j + N + M);
            }
        }
    }
    
    memset(visit, false, sizeof(visit));
    memset(scc, 0, sizeof(scc));
    sccNum = 0;
    
    for (int i = 0; i < (N + M) * 2 + 1; i++)
        if (!visit[i]) dfs1(i);
        
    while (!st.empty()) {
        int cur = st.top();
        st.pop();
        if (scc[cur] == 0) {
            sccNum++;
            dfs2(cur);
        }
    }
    
    for (int i = 1; i <= (N + M); i++)
        if (scc[-i + N + M] == scc[i + N + M]) {
            cout << "0";
            return 0;
        }
    cout << "1";
    
    return 0;
}