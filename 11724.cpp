#include <iostream>
#include <utility>
#include <vector>

using namespace std;

vector<int> graph[1001];
bool visit[1001];

void dfs (int x) {
    for (int i = 0; i < graph[x].size(); i++) {
        if (visit[graph[x][i]]) continue;
        visit[graph[x][i]] = true;
        dfs(graph[x][i]);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    
    while (m--) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    for (int i = 1; i <= 1000; i++) visit[i] = false;
    
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (!visit[i]) {
            dfs(i);
            cnt++;
        }
    
    cout << cnt;
    
    return 0;
}