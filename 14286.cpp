#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int INF = 1<<30;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m; cin >> n >> m;
    int c[500 + 1][500 + 1], f[500 + 1][500 + 1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            c[i][j] = 0, f[i][j] = 0;
        }
    
    vector<int> graph[500 + 1];
    
    int tempa, tempb, tempc;
    for (int i = 0; i < m; i++) {
        cin >> tempa >> tempb >> tempc;
        
        c[tempa][tempb] = tempc;
        c[tempb][tempa] = tempc;
        graph[tempa].push_back(tempb);
        graph[tempb].push_back(tempa);
    }
    
    int start, finish; cin >> start >> finish;
    
    int ans = 0;
    while (true) {
        int prev[500 + 1];
        for (int i = 1; i <= n; i++) prev[i] = -1;
        
        queue<int> q;
        q.push(start);
        while (!q.empty() && prev[finish] == -1) {
            int cur = q.front();
            q.pop();
            for (int next: graph[cur]) {
                if (prev[next] != -1) continue;
                if (c[cur][next] - f[cur][next] > 0) {
                    q.push(next);
                    prev[next] = cur;
                    if (next == finish) break;
                }
            }
        }
        
        if (prev[finish] == -1) break;
        
        int flow = INF;
        for (int i = finish; i != start; i = prev[i]) {
            flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
        }
        
        for (int i = finish; i != start; i = prev[i]) {
            f[prev[i]][i] += flow;
            f[i][prev[i]] -= flow;
        }
        ans += flow;
    }
    
    cout << ans;
    
    return 0;
}