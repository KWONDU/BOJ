#include <iostream>
#include <memory.h>
#include <utility>
#include <vector>
#include <stack>

using namespace std;

int V, E, A, B;
vector<int> adj[10000 + 1];

int dfn[10000 + 1], low[10000 + 1], order, bccNum;
bool acPoint[10000 + 1];
vector<pair<int, int>> BCC[10000 + 1];
stack<pair<int, int>> s;

void dfs (int cur, int par) {
    dfn[cur] = low[cur] = ++order;

    int childCnt = 0;
    for (int nxt : adj[cur]) {
        if (nxt == par) continue;

        if (dfn[nxt] == 0) {
            s.push(make_pair(cur, nxt));
            childCnt++;
            dfs(nxt, cur);

            low[cur] = min(low[cur], low[nxt]);
            if (dfn[cur] <= low[nxt]) {
                if (par != -1) acPoint[cur] = true;

                bccNum++;
                while (s.top() != make_pair(cur, nxt)) {
                    BCC[bccNum].push_back(s.top());
                    s.pop();
                }
                BCC[bccNum].push_back(s.top());
                s.pop();
            }
        } else if (dfn[cur] > dfn[nxt]) {
            low[cur] = min(low[cur], dfn[nxt]);
            s.push(make_pair(cur, nxt));
        }
    }

    if (par == -1 && childCnt >= 2) acPoint[cur] = true;

    return ;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> V >> E;
    while (E--) {
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }

    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(acPoint, false, sizeof(acPoint));
    order = 0, bccNum = 0;

    for (int i = 1; i <= V; i++) {
        if (dfn[i] == 0) dfs(i, -1);
    }

    vector<int> ans;
    for (int i = 1; i <= V; i++) {
        if (acPoint[i]) ans.push_back(i);
    }

    cout << ans.size() << "\n";
    for (int x : ans) cout << x << " ";

    return 0;
}