#include <iostream>
#include <vector>

using namespace std;

vector<int> tree[1000000 + 1];
int adaptor[1000000 + 1][2];

int min (int x, int y) {
    return x < y ? x : y;
}

int dp (int cur, int par, int chk) {
    if (adaptor[cur][chk] != -1) return adaptor[cur][chk];
    
    adaptor[cur][chk] = chk == 1 ? 1 : 0;
    for (int child : tree[cur]) {
        if (child == par) continue;
        
        if (!chk) adaptor[cur][chk] += dp(child, cur, 1);
        else adaptor[cur][chk] += min(dp(child, cur, 0), dp(child, cur, 1));
    }
    return adaptor[cur][chk];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    for (int i = 1; i <= N; i++) {
        adaptor[i][0] = -1;
        adaptor[i][1] = -1;
    }
    
    cout << min(dp(1, -1, 0), dp(1, -1, 1));
    
    return 0;
}