#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

const int MAXNUM = 500000 + 1;

// input
int N, M, S, P;
vector<int> road[MAXNUM], restaurant;
int money[MAXNUM];

// kosaraju's algorithm
vector<int> roadR[MAXNUM];
bool visit[MAXNUM];
int scc[MAXNUM], sccNum;
stack<int> st;

int moneySCC[MAXNUM];
vector<int> roadSCC[MAXNUM];
bool restaurantChk[MAXNUM];

void dfs1 (int cur) {
    visit[cur] = true;
    for (int nxt : road[cur])
        if (!visit[nxt]) dfs1(nxt);
    st.push(cur);
    
    return ;
}

void dfs2 (int cur) {
    scc[cur] = sccNum;
    moneySCC[sccNum] += money[cur];
    for (int nxt : roadR[cur]) {
        if (scc[nxt] == 0) dfs2(nxt);
        else if (scc[cur] != scc[nxt]) roadSCC[scc[nxt]].push_back(scc[cur]);
    }
    
    return ;
}

// calculate
int dp[MAXNUM], ans;

int max (int n1, int n2) {
    return n1 > n2 ? n1 : n2;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // input
    cin >> N >> M;
    for (int M_ = 0; M_ < M; M_++) {
        int u, v;
        cin >> u >> v;
        road[u].push_back(v);
        roadR[v].push_back(u);
    }
    for (int i = 1; i <= N; i++) cin >> money[i];
    cin >> S >> P;
    for (int P_ = 0; P_ < P; P_++) {
        int x;
        cin >> x;
        restaurant.push_back(x);
    }
    
    // kosaraju's algorithm
    for (int i = 1; i <= N; i++) visit[i] = false;
    for (int i = 1; i <= N; i++) scc[i] = 0;
    sccNum = 0;
    
    for (int i = 1; i <= N; i++)
        if (!visit[i]) dfs1(i);
    
    for (int i = 1; i <= N; i++) moneySCC[i] = 0;
    
    while (!st.empty()) {
        int cur = st.top();
        st.pop();
        
        if (scc[cur] == 0) {
            sccNum++;
            dfs2(cur);
        }
    }
    
    for (int i = 1; i <= sccNum; i++) restaurantChk[i] = false;
    for (int r : restaurant) restaurantChk[scc[r]] = true;
    
    // calculate
    for (int i = 1; i <= sccNum; i++) dp[i] = 0;
    ans = 0;
    
    queue<int> q;
    q.push(scc[S]);
    dp[scc[S]] = moneySCC[scc[S]];
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        if (restaurantChk[cur]) ans = max(ans, dp[cur]);
        
        for (int nxt : roadSCC[cur]) {
            if (dp[nxt] < dp[cur] + moneySCC[nxt]) {
                dp[nxt] = dp[cur] + moneySCC[nxt];
                q.push(nxt);
            }
        }
    }
    
    cout << ans;
    
    return 0;
}