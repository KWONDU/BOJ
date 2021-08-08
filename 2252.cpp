#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> order[32000 + 1];

int cnt[32000 + 1];

void topologicalSort () {
    queue<int> q;
    
    for (int i = 1; i <= N; i++)
        if (cnt[i] == 0) q.push(i);
    
    int cur;
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        cout << cur << " ";
        for (int nxt: order[cur]) {
            cnt[nxt]--;
            if (cnt[nxt] == 0) q.push(nxt);
        }
    }
    
    return;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for (int i = 1; i <= N; i++) cnt[i] = 0;
    while (M--) {
        int A, B;
        cin >> A >> B;
        order[A].push_back(B);
        cnt[B]++;
    }
    
    topologicalSort();
    
    return 0;
}