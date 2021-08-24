#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int MAX = 500 * 2 + 1;

int n, k, a[MAX], b[MAX];
bool visit[MAX];
vector<int> V[MAX];

void init () {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    
    return ;
}

void input () {
    init();
    
    int row, col;
    
    cin >> n >> k;
    while (k--) {
        cin >> row >> col;
        V[row].push_back(col + n);
    }
    
    return ;
}

bool dfs (int cur) {
    visit[cur] = true;
    
    for (int nxt : V[cur]) {
        if (b[nxt] == 0 || (!visit[b[nxt]] && dfs(b[nxt]))) {
            a[cur] = nxt;
            b[nxt] = cur;
            return true;
        }
    }
    return false;
}

int vertexCover () {
    int ans = 0;
    
    for (int i = 1; i <= n; i++) {
        memset(visit, false, sizeof(visit));
        if (dfs(i)) ans ++;
    }
    
    return ans;
}

int main () {ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    cout << vertexCover();

    return 0;
}