#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> road[10000 + 1];
int cntConnect[10000 + 1];

int n, m, start, finish;

vector<pair<int, int>> rev[10000 + 1];

vector<bool> chk[10000 + 1];
int maxTime[10000 + 1], cnt;

void dfsR (int cur) {
    for (int i = 0; i < rev[cur].size(); i++) {
        if (chk[cur][i]) continue;
        
        if (maxTime[cur] == maxTime[rev[cur][i].first] + rev[cur][i].second) {
            cnt++;
            chk[cur][i] = true;
            dfsR(rev[cur][i].first);
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cntConnect[i] = 0;
    while (m--) {
        int s, f, t;
        cin >> s >> f >> t;
        road[s].push_back(make_pair(f, t));
        cntConnect[f]++;
        
        rev[f].push_back(make_pair(s, t));
        chk[f].push_back(false);
    }
    cin >> start >> finish;
    
    for (int i = 1; i <= n; i++) maxTime[i] = 0;
    
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (auto nxt : road[cur]) {
            cntConnect[nxt.first]--;
            maxTime[nxt.first] = max(maxTime[nxt.first], maxTime[cur] + nxt.second);
            
            if (cntConnect[nxt.first] == 0) q.push(nxt.first);
        }
    }
    
    cout << maxTime[finish] << "\n";
    
    cnt = 0;
    dfsR(finish);
    
    cout << cnt;
    
    return 0;
}