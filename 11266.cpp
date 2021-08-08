#include <iostream>
#include <memory.h>
#include <vector>
#include <algorithm>

using namespace std;

int V, E, A, B, visit[10000 + 1], order, chk[10000 + 1];
vector<int> v[10000 + 1];

int dfs (int cur, bool root) {
    visit[cur] = ++order;

    int ret = visit[cur], nxtCnt = 0;
    for (int nxt : v[cur]) {
        if (visit[nxt] == 0) {
            nxtCnt++;
            
            int nxtLow = dfs(nxt, false);
            if (!root && nxtLow >= visit[cur]) chk[cur] = true;

            ret = min(ret, nxtLow);
        } else ret = min(ret, visit[nxt]);
    }

    if (root && nxtCnt > 1) chk[cur] = true;
    
    return ret;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> V >> E;
    while (E--) {
        cin >> A >> B;
        v[A].push_back(B);
        v[B].push_back(A);
    }

    for (int i = 1; i <= V; i++) sort(v[i].begin(), v[i].end());

    memset(visit, 0, sizeof(visit));
    memset(chk, false, sizeof(chk));

    order = 0;

    for (int i = 1; i <= V; i++)
        if (visit[i] == 0) dfs(i, true);
    
    int sz = 0;
    for (int i = 1; i <= V; i++)
        if (chk[i]) sz++;
    cout << sz << "\n";

    for (int i = 1; i <= V; i++)
        if (chk[i]) cout << i << " ";

    return 0;
}