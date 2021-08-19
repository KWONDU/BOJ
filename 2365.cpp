#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 50 * 2 + 1 + 1, MANY = (50 + 50 + 50 * 50) * 2 + 1;
const int MAXFLOW = 10000, INF = 50 * 10000 + 1;

struct edge {
    int x, c, f;
    edge *d;
    edge () {};
    edge (int x, int c, int f, edge* d) : x(x), c(c), f(f), d(d) {};
} nedge[MANY];
int num_edge;

int S, E, maxFlow;
edge* pre[MAX];
vector<edge*> V[MAX];

void make_edge (int p, int q, int cap) {
    nedge[num_edge] = edge(q, cap, 0, NULL);
    edge *now1 = &nedge[num_edge ++];
    nedge[num_edge] = edge(p, 0, 0, NULL);
    edge *now2 = &nedge[num_edge ++];
    now1->d = now2;
    now2->d = now1;
    V[p].push_back(now1);
    V[q].push_back(now2);
    
    return ;
}

int N, sum[MAX];

void input () {
    cin >> N;
    for (int i = 1; i <= N * 2; i++) cin >> sum[i];
    
    S = 0, E = N * 2 + 1;
    
    for (int i = 1; i <= N; i++) make_edge(S, i, sum[i]);
    for (int i = 1; i <= N; i++) {
        for (int j = N + 1; j <= N * 2; j++) make_edge(i, j, min(sum[i], sum[j]));
    }
    for (int i = N + 1; i <= N * 2; i++) make_edge(i, E, sum[i]);
    
    return ;
}

bool edmondKarp (int limit) {
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

void cycle (int limit) {
    for (int i = 0; i < MAX; i++) {
        if (1 <= i && i <= N) {
            for (edge *e : V[i]) {
                if (e->x != S) e->c = min(limit, min(sum[i], sum[e->x]));
            }
        }
        
        for (edge *e : V[i]) e->f = 0;
    }
    num_edge = 0, maxFlow = 0;
    
    while (true) {
        if (!edmondKarp(limit)) break ;
    }
    
    return ;
}

int binarySearch () {
    cycle(MAXFLOW);
    
    int max_maxFlow = maxFlow;
    
    int l = 0, r = MAXFLOW, m;
    while (l < r) {
        m = (l + r) / 2;
        
        cycle(m);
        
        if (maxFlow < max_maxFlow) l = m + 1;
        else r = m;
    }
    
    cycle(l);
    
    return l;
}

void output () {
    cout << binarySearch() << "\n";
    for (int i = 1; i <= N; i++) {
        for (edge *e : V[i]) {
            if (e->x != S) cout << e->f << " ";
        }
        cout << "\n";
    }
    
    return ;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    output();
    
    return 0;
}