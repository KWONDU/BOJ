#include <iostream>
#include <memory.h>
#include <vector>
#include <queue>

using namespace std;

const int MAX = (400 + 1) * 2;

int in (int ver) {
    return ver * 2;
}

int out (int ver) {
    return ver * 2 + 1;
}

int N, P, s = out(1), e = in(2), c[MAX][MAX], f[MAX][MAX], pre[MAX];
vector<int> v[MAX];

void input () {
    int a, b;
    
    for (int i = 0; i < MAX; i++) memset(c[i], 0, sizeof(c[i]));
    for (int i = 0; i < MAX; i++) memset(f[i], 0, sizeof(f[i]));
    
    cin >> N >> P;
    while (P--) {
        cin >> a >> b;
        int aIn = in(a), aOut = out(a), bIn = in(b), bOut = out(b);
        v[aOut].push_back(bIn);
        v[bIn].push_back(aOut);
        v[bOut].push_back(aIn);
        v[aIn].push_back(bOut);
        c[aOut][bIn] = 1;
        c[bOut][aIn] = 1;
    }
    
    for (int i = 1; i <= N; i++) {
        int iIn = in(i), iOut = out(i);
        v[iIn].push_back(iOut);
        v[iOut].push_back(iIn);
        c[iIn][iOut] = 1;
    }
    
    return ;
}

void bfs () {
    memset(pre, -1, sizeof(pre));
    
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (int nxt : v[cur]) {
            if (pre[nxt] == -1 && c[cur][nxt] - f[cur][nxt] > 0) {
                pre[nxt] = cur;
                q.push(nxt);
            }
        }
    }
    
    return ;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    
    while (true) {
        bfs();
        if (pre[e] == -1) break;
        
        for (int i = e; i != s; i = pre[i]) {
            f[pre[i]][i] ++;
            f[i][pre[i]] --;
        }
    }
    
    int ans = 0;
    for (int i = 0; i < MAX; i++) ans += f[i][e];
    cout << ans;
    
    return 0;
}