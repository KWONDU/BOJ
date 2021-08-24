#include <iostream>
#include <memory.h>
#include <vector>

using namespace std;

const int MAX = (1000 + 1) * 2;

int N, M, c[MAX][MAX], f[MAX][MAX], a[MAX], b[MAX];
bool visit[MAX];
vector<int> V[MAX];

void init () {
    for (int i = 0; i < MAX; i++) memset(c[i], 0, sizeof(c[i]));
    for (int i = 0; i < MAX; i++) memset(f[i], 0, sizeof(f[i]));
    memset(a, -1, sizeof(a));
    memset(b, -1, sizeof(b));
    
    return ;
}

void make_edge (int p, int q, int cap) {
    V[p].push_back(q);
    V[q].push_back(p);
    c[p][q] += cap;
    
    return ;
}

void input () {
    init();
    
    int t, j;
    
    cin >> N >> M;
    
    for (int i = 1; i <= N; i++) {
        cin >> t;
        while (t--) {
            cin >> j;
            make_edge(i, N + j, 1);
        }
    }
    
    return ;
}

bool dfs (int cur) {
    visit[cur] = true;
    for (int nxt : V[cur]) {
        if (b[nxt] == -1 || (!visit[b[nxt]] && dfs(b[nxt]))) {
            a[cur] = nxt;
            b[nxt] = cur;
            return true;
        }
    }
    return false;
}

int bipartiteMatching () {
    int ans = 0;
    
    for (int i = 1; i <= N; i++) {
        memset(visit, false, sizeof(visit));
        if (dfs(i)) ans ++;
    }
    
    return ans;
}

int main () { ios_base::sync_with_stdio(false); cout.tie(NULL); cout.tie(NULL);
    input();
    cout << bipartiteMatching();

    return 0;
}