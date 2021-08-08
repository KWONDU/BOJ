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
    int c[200 + 200 + 2][200 + 200 + 2], f[200 + 200 + 2][200 + 200 + 2];
    for (int i = 0; i <= n + m + 1; i++)
        for (int j = 0; j <= n + m + 1; j++) {
            c[i][j] = 0, f[i][j] = 0;
        }
    
    int start = 0, finish = n + m + 1;
    vector<int> barn[200 + 200 + 2];
    
    for (int i = 1; i <= n; i++) {
        c[start][i] = 1;
        barn[start].push_back(i);
        barn[i].push_back(start);
    }
    for (int i = 1; i <= n; i++) {
        int s, temp; cin >> s;
        for (int j = 0; j < s; j++) {
            cin >> temp;
            c[i][temp + n] = 1;
            barn[i].push_back(temp + n);
            barn[temp + n].push_back(i);
        }
    }
    for (int i = n + 1; i <= n + m; i++) {
        c[i][finish] = 1;
        barn[i].push_back(finish);
        barn[finish].push_back(i);
    }
    
    int cnt = 0;
    while (true) {
        int prev[200 + 200 + 2];
        for (int i = 0; i <= n + m + 1; i++) prev[i] = -1;
        
        queue<int> q;
        q.push(start);
        while (!q.empty() && prev[finish] == -1) {
            int cur = q.front();
            q.pop();
            
            for (int next: barn[cur]) {
                if (prev[next] != -1) continue;
                if (c[cur][next] - f[cur][next] > 0) {
                    q.push(next);
                    prev[next] = cur;
                    if (next == finish) break;
                }
            }
        }
        
        if (prev[finish] == -1) break;
        
        int flow = n + 1;
        for (int i = finish; i != start; i = prev[i]) {
            flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
        }
        
        for (int i = finish; i != start; i = prev[i]) {
            f[prev[i]][i] += flow;
            f[i][prev[i]] -= flow;
        }
        
        cnt += flow;
    }
    
    cout << cnt;
    
    return 0;
}