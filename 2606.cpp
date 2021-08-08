#include <iostream>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector<int> network[100 + 1];
    
    int m;
    cin >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        network[x].push_back(y);
        network[y].push_back(x);
    }
    
    bool visit[100 + 1];
    for (int i = 1; i <= n; i++) visit[i] = false;
    
    queue<int> q;
    visit[1] = true;
    q.push(1);
    
    int cnt = 0;
    while(!q.empty()) {
        int chk = q.front();
        q.pop();
        
        for (int i = 0; i < network[chk].size(); i++)
            if (!visit[network[chk][i]]) {
                visit[network[chk][i]] = true;
                cnt++;
                q.push(network[chk][i]);
            }
    }
    
    cout << cnt;
    
    return 0;
}