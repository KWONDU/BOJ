#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

bool* chkdfs;
void dfs (vector< vector<int> > tree, int v) {
    chkdfs[v] = true;
    cout << v << " ";
    for (int t: tree[v]) {
        if (chkdfs[t]) continue;
        dfs(tree, t);
    }
    return;
}

bool* chkbfs;
void bfs (vector< vector<int> > tree, int v) {
    queue<int> q;
    q.push(v);
    chkbfs[v] = true;
    while (!q.empty()) {
        int temp = q.front();
        cout << temp << " ";
        q.pop();
        for (int t: tree[temp]) {
            if (chkbfs[t]) continue;
            q.push(t);
            chkbfs[t] = true;
        }
    }
    return;
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m, v; cin >> n >> m >> v;
    vector< vector<int> > tree; vector<int> tempvector;
    for (int i = 0; i <= n; i++) tree.push_back(tempvector);
    int a, b; for (int i = 0; i < m; i++) {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) sort(tree[i].begin(), tree[i].end());
    
    chkdfs = new bool[n + 1]; for (int i = 1; i <= n; i++) chkdfs[i] = false;
    dfs(tree, v);
    cout << "\n";
    chkbfs = new bool[n + 1]; for (int i = 1; i <= n; i++) chkbfs[i] = false;
    bfs(tree, v);
    
    return 0;
}