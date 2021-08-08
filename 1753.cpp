#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <queue>

using namespace std;

#define INF 1<<30

struct cmp {
    bool operator () (pair<int, int> p1, pair<int, int> p2) {
        return p1.second > p2.second;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int V, E; cin >> V >> E;
    int K; cin >> K;
    
    vector< pair<int, int> > line[20000 + 1];
    int tempu, tempv, tempw;
    for (int i = 0; i < E; i++) {
        cin >> tempu >> tempv >> tempw;
        line[tempu].push_back({tempv, tempw});
    }
    
    int dis[20000 + 1];
    for (int i = 1; i <= V; i++) dis[i] = INF;
    
    priority_queue<pair<int, int>, vector< pair<int, int> >, cmp> pq;
    pq.push({K, 0});
    dis[K] = 0;
    while (!pq.empty()) {
        int pos = pq.top().first;
        pq.pop();
        
        for (pair<int, int> i: line[pos]) {
            if (dis[pos] + i.second < dis[i.first]) {
                dis[i.first] = dis[pos] + i.second;
                pq.push({i.first, dis[i.first]});
            }
        }
    }
    
    for (int i = 1; i <= V; i++) {
        if (dis[i] == INF) cout << "INF\n";
        else cout << dis[i] << "\n";
    }
    
    return 0;
}