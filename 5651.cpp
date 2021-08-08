#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int k; cin >> k;
    while (k--) {
        int n, m; cin >> n >> m;
        int capacity[300 + 1][300 + 1], flow[300 + 1][300 + 1];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                capacity[i][j] = 0 , flow[i][j] = 0;
            }
        vector<int> graph[300 + 1];
        
        vector< pair<int, int> > line;
        int f, t, b;
        for (int i = 0; i < m; i++) {
            cin >> f >> t >> b;
            graph[f].push_back(t);
            graph[t].push_back(f);
            capacity[f][t] += b;
            
            line.push_back(make_pair(f, t));
        }
        
        int totalflow = 0, start = 1, finish = n;
        while (true) {
            int prev[300 + 1]; for (int i = 1; i <= n; i++) prev[i] = -1;
            
            queue<int> q;
            q.push(start);
            while (!q.empty() && prev[finish] == -1) {
                int cur = q.front();
                q.pop();
                
                for (int next: graph[cur]) {
                    if (prev[next] != -1) continue;
                    if (capacity[cur][next] - flow[cur][next] > 0) {
                        q.push(next);
                        prev[next] = cur;
                        if (next == finish) break;
                    }
                }
            }
            
            if (prev[finish] == -1) break;
            
            int tempflow = 20000 + 1;
            for (int i = finish; i != start; i = prev[i]) {
                tempflow = min(tempflow, capacity[prev[i]][i] - flow[prev[i]][i]);
            }
            
            for (int i = finish; i != start; i = prev[i]) {
                flow[prev[i]][i] += tempflow;
                flow[i][prev[i]] -= tempflow;
            }
            
            totalflow += tempflow;
        }
        
        int cnt = 0;
        for (auto l: line) {
            int a = l.first, b = l.second;
            
            int prev[300 + 1]; for (int i = 1; i <= n; i++) prev[i] = -1;
            
            queue<int> q;
            q.push(a);
            while (!q.empty() && prev[b] == -1) {
                int cur = q.front();
                q.pop();
                
                for (int next: graph[cur]) {
                    if (prev[next] != -1) continue;
                    if (capacity[cur][next] - flow[cur][next] > 0) {
                        q.push(next);
                        prev[next] = cur;
                        if (next == b) break;
                    }
                }
            }
            
            if (prev[b] == -1) cnt++;
        }
        
        cout << cnt << "\n";
    }
    
    return 0;
}