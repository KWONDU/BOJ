#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 500 + 1, MANY = 10000 * 2, INF = 10000 * 100 + 1;

struct edge {
    int x, c, f;
    edge *d;
    edge () {};
    edge (int x, int c, int f, edge* d) : x(x), c(c), f(f), d(d) {};
} nedge[MANY];

int num_edge, maxFlow;
edge* pre[MAX];
vector<edge*> V[MAX];

void make_edge (int p, int q, int cap) {
    nedge[num_edge] = edge(q, cap, 0, NULL);
    edge* now1 = &nedge[num_edge++];
    nedge[num_edge] = edge(p, cap, 0, NULL);
    edge* now2 = &nedge[num_edge++];
    now1->d = now2;
    now2->d = now1;
    V[p].push_back(now1);
    V[q].push_back(now2);
    
    return ;
}

int n, m, a, b, c, s, t;

void input () {
    num_edge = 0, maxFlow = 0;
    
    cin >> n >> m;
        
    while (m--) {
        cin >> a >> b >> c;
        make_edge(a, b, c);
    }
    
    cin >> s >> t;
    
    return ;
}

bool edmondKarp () {
    for (int i = 0; i < MAX; i++) pre[i] = NULL;
    queue<int> Q;
    
    Q.push(s);
    while (!Q.empty() && !pre[t]) {
        int cur = Q.front(); Q.pop();
        for (edge* nxt : V[cur]) {
            if (!pre[nxt->x] && nxt->c > nxt->f) {
                pre[nxt->x] = nxt;
                Q.push(nxt->x);
                
                if (pre[t]) break;
            }
        }
    }
    
    if (!pre[t]) return false;
    
    int flow = INF;
    for (int i = t; i != s; i = pre[i]->d->x) flow = min(flow, pre[i]->c - pre[i]->f);
    for (int i = t; i != s; i = pre[i]->d->x) {
        pre[i]->f += flow;
        pre[i]->d->f -= flow;
    }
    
    maxFlow += flow;
    
    return true;
}

int main () {ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    input();
    while (edmondKarp()) {}
    cout << maxFlow;

    return 0;
}