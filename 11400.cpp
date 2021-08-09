#include <iostream>
#include <memory.h>
#include <utility>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int V, E, A, B;
vector<int> adj[100000 + 1];

int dfn[100000 + 1], low[100000 + 1], order, bccNum;
vector<pair<int, int>> acBridge;
vector<pair<int, int>> BCC[100000 + 1];
stack<pair<int, int>> s;

void dfs (int cur, int par) {
    dfn[cur] = low[cur] = ++order;

    for (int nxt : adj[cur]) {
        if (nxt == par) continue;

        if (dfn[nxt] == 0) {
            s.push(make_pair(cur, nxt));
            dfs(nxt, cur);

            low[cur] = min(low[cur], low[nxt]);
            if (dfn[cur] <= low[nxt]) {
                if (dfn[cur] < low[nxt]) acBridge.push_back(make_pair(cur, nxt));

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

    return ;
}

bool comp (pair<int, int> p1, pair<int, int> p2) {
    if (p1.first == p2.first) return p1.second < p2.second;
    else return p1.first < p2.first;
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
    order = 0, bccNum = 0;

    for (int i = 1; i <= V; i++) {
        if (dfn[i] == 0) dfs(i, -1);
    }

    cout << acBridge.size() << "\n";

    vector<pair<int, int>> ans;
    for (auto x : acBridge) {
        if (x.first > x.second) ans.push_back(make_pair(x.second, x.first));
        else ans.push_back(x);
    }

    sort(ans.begin(), ans.end(), comp);
    for (auto y : ans) cout << y.first << " " << y.second << "\n";

    return 0;
}