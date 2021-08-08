#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const long long int INF = 10000000000 + 1;

int N, M, A, B;
long long int W;
int start, finish;

vector<pair<int, long long int>> bus[1000 + 1];

long long int minCost[1000 + 1];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> A >> B >> W;
        bus[A].push_back(make_pair(B, W));
    }
    cin >> start >> finish;
    
    for (int i = 1; i <= N; i++) minCost[i] = INF;
    
    minCost[start] = 0;
    
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(start, 0));
    while (!pq.empty()) {
        int cur = pq.top().first;
        int cost = -pq.top().second;
        pq.pop();
        
        if (minCost[cur] < cost) continue;
        
        for (auto nxt: bus[cur]) {
            if (minCost[nxt.first] > cost + nxt.second) {
                minCost[nxt.first] = cost + nxt.second;
                pq.push(make_pair(nxt.first, -minCost[nxt.first]));
            }
        }
    }
    
    cout << minCost[finish];
    
    return 0;
}