#include <iostream>
#include <memory.h>
#include <utility>
#include <vector>
#include <stack>

using namespace std;

const int MAX = 1e5 + 1;

bool flag;

int N, M, x, y;
vector<int> adj[MAX];

int dfn[MAX], low[MAX], b[MAX], order, bccNum, cnt[MAX];
vector<pair<int, int>> BCC[MAX];
stack<pair<int, int>> S;

void dfs (int cur, int par = -1) {
    dfn[cur] = low[cur] = ++order;
    
    for (int nxt : adj[cur]) {
        if (nxt == par) continue;
        
        if (dfn[nxt] == 0) {
            S.push(make_pair(cur, nxt));
            dfs(nxt, cur);
            
            low[cur] = min(low[cur], low[nxt]);
            if (dfn[cur] <= low[nxt]) {
                bccNum++;
                while (S.top() != make_pair(cur, nxt)) {
                    if (b[S.top().first] == 0) b[S.top().first] = bccNum;
                    else if (b[S.top().first] != bccNum) flag = false;
                    if (b[S.top().second] == 0) b[S.top().second] = bccNum;
                    else if (b[S.top().second] != bccNum) flag = false;
                    
                    BCC[bccNum].push_back(S.top());
                    S.pop();
                }
                
                if (BCC[bccNum].size() > 0) {
                    if (b[S.top().first] == 0) b[S.top().first] = bccNum;
                    else if (b[S.top().first] != bccNum) flag = false;
                    if (b[S.top().second] == 0) b[S.top().second] = bccNum;
                    else if (b[S.top().second] != bccNum) flag = false;
                }
                
                BCC[bccNum].push_back(S.top());
                S.pop();
            }
        } else if (dfn[cur] > dfn[nxt]) {
            low[cur] = min(low[cur], dfn[nxt]);
            S.push(make_pair(cur, nxt));
        }
    }
    
    return ;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    while (M--) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(b, 0, sizeof(b));
    order = 0, bccNum = 0;
    
    flag = true;
    
    for (int i = 1; i <= N; i++) {
        if (dfn[i] == 0) dfs(i);
    }
    
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= N; i++) cnt[b[i]]++;
    
    for (int i = 1; i <= bccNum; i++) {
        if (BCC[i].size() == 1) continue;
        else if (BCC[i].size() != cnt[i]) flag = false;
    }
    
    cout << (flag ? "Cactus" : "Not cactus");

    return 0;
}