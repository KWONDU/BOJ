#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;

vector<pair<int, int>> toy[100 + 1];
int cntConnect[100 + 1];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for (int i = 1; i <= N; i++) cntConnect[i] = 0;
    while (M--) {
        int X, Y, K;
        cin >> X >> Y >> K;
        toy[X].push_back(make_pair(Y, K));
        cntConnect[Y]++;
    }
    
    int block[100 + 1];
    for (int i = 1; i <= N - 1; i++) block[i] = 0;
    block[N] = 1;
    
    vector<int> basic;
    
    queue<int> q;
    q.push(N);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        bool chk = false;
        for (auto nxt : toy[cur]) {
            chk = true;
            cntConnect[nxt.first]--;
            block[nxt.first] += (block[cur] * nxt.second);
            if (cntConnect[nxt.first] == 0) q.push(nxt.first);
        }
        
        if (!chk) basic.push_back(cur);
    }
    
    sort(basic.begin(), basic.end());
    for (int i : basic) cout << i << " " << block[i] << "\n";
    
    return 0;
}