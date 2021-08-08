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
    
    int n, p; cin >> n >> p;
    
    int c[400 + 1][400 + 1];
    int f[400 + 1][400 + 1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            c[i][j] = 0, f[i][j] = 0;
        }
    
    vector<int> road[400 + 1];
    int temp1, temp2;
    for (int i = 0; i < p; i++) {
        cin >> temp1 >> temp2;
        c[temp1][temp2] = 1;
        c[temp2][temp1] = 0;
        road[temp1].push_back(temp2);
        road[temp2].push_back(temp1);
    }
    
    int prev[400 + 1];
    int total = 0, start = 1, finish = 2;
    while (true) {
        for (int i = 1; i <= n; i++) prev[i] = -1;
        
        queue<int> q;
        q.push(start);
        while (!q.empty() && prev[finish] == -1) {
            int cur = q.front();
            q.pop();
            for (int next: road[cur]) {
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
        
        total += flow;
    }
    
    cout << total;
    
    return 0;
}