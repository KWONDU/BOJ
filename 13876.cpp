#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 50 * 2 + 1 + 1, MANY = 50 + 50 + 50 * 50 / 2 + 1;
const int INF = 50 + 1;

struct edge {
    int x, c, f;
    edge* d;
    edge () {};
    edge (int x, int c, int f, edge* d) : x(x), c(c), f(f), d(d) {};
} nedge[MANY];
int num_edge;

int N, S, E, maxFlow;
edge* pre[MAX];
vector<edge*> V[MAX];

void make_edge (int p, int q, int cap) {
    nedge[num_edge] = edge(q, cap, 0, NULL);
    edge* now1 = &nedge[num_edge ++];
    nedge[num_edge] = edge(p, 0, 0, NULL);
    edge* now2 = &nedge[num_edge ++];
    now1->d = now2;
    now2->d = now1;
    V[p].push_back(now1);
    V[q].push_back(now2);
    
    return ;
}

//*//
struct victim {
    int a, b;
} vote[MAX];
//*//

void input () {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> vote[i].a >> vote[i].b;
    
    S = 0, E = N * 2 + 1;
    
    return ;
}

void init () {
    for (int i = 0; i < MAX; i++) V[i].clear();
    num_edge = 0, maxFlow = 0;
    
    return ;
}

bool edmondKarp () {
    for (int i = 0; i < MAX; i++) pre[i] = NULL;
    queue<int> Q;
    
    Q.push(S);
    while (!Q.empty() && !pre[E]) {
        int cur = Q.front(); Q.pop();
        for (edge *nxtEdge : V[cur]) {
            if (!pre[nxtEdge->x] && nxtEdge->c > nxtEdge->f) {
                pre[nxtEdge->x] = nxtEdge;
                Q.push(nxtEdge->x);
                
                if (pre[E]) break;
            }
        }
    }
    
    if (!pre[E]) return false;
    
    int flow = INF;
    for (int i = E; i != S; i = pre[i]->d->x) flow = min(flow, pre[i]->c - pre[i]->f);
    for (int i = E; i != S; i = pre[i]->d->x) {
        pre[i]->f += flow;
        pre[i]->d->f -= flow;
    }
    
    maxFlow += flow;
    
    return true;
}

bool reveal (int wolf) {
    init();
    
    int wolf_vote = 0;
    for (int i = 1; i <= N; i++) {
        if (vote[i].a == wolf || vote[i].b == wolf) wolf_vote ++;
        else if (i != wolf) {
            make_edge(S, i, 1);
            make_edge(i, vote[i].a + N, 1);
            make_edge(i, vote[i].b + N, 1);
        }
    }
    for (int i = 1; i <= N; i++) {
        if (i == wolf) continue ;
        else if (i == vote[wolf].a || i == vote[wolf].b) make_edge(i + N, E, wolf_vote - 2);
        else make_edge(i + N, E, wolf_vote - 1);
    }
    
    while (true) {
        if (!edmondKarp()) break ;
    }
    
    if (maxFlow + wolf_vote + 1 == N) return false;
    else return true;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (reveal(i)) cnt ++;
    }
    
    cout << cnt;
    
    return 0;
}