#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

const int X = 1000;

int par[X];
int sz[X];

typedef struct {
    int c, f, t;
} line;

bool ascending (line l1, line l2) {
    return l1.c < l2.c;
}

int find (int x);
void merge (int a, int b);

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n, m, k;
    while (true) {
        cin >> n >> m >> k;
        if (n == 0 && m == 0 && k == 0)
            break;
        
        vector<line> tree;
        line templine;
        char char_c;
        int f, t;
        for (int i = 0; i < m; i++) {
            cin >> char_c >> f >> t;
            if (char_c == 'B')
                templine.c = 1;
            else
                templine.c = 0;
            templine.f = f;
            templine.t = t;
            tree.push_back(templine);
        }
        
        for (int i = 0; i < X; i++)
            par[i] = i;
        for (int i = 0; i < n; i++)
            sz[i] = 1;
        
        sort(tree.begin(), tree.end(), ascending);
        int mincost = 0;
        for (int i = 0; i < m; i++) {
            if (find(tree[i].f) == find(tree[i].t))
                continue;
            
            merge(tree[i].f, tree[i].t);
            mincost += tree[i].c;
        }
        
        for (int i = 0; i < X; i++)
            par[i] = i;
        for (int i = 0; i < n; i++)
            sz[i] = 1;
        
        int maxcost = 0;
        for (int i = m - 1; i >= 0; i--) {
            if (find(tree[i].f) == find(tree[i].t))
                continue;
            
            merge(tree[i].f, tree[i].t);
            maxcost += tree[i].c;
        }
        
        if (mincost <= k && k <= maxcost)
            cout << "1\n";
        else
            cout << "0\n";
    }
}

int find (int x) {
    if (x == par[x])
        return x;
    return par[x] = find(par[x]);
}

void merge (int a, int b) {
    a = find(a); b = find(b);
    
    if (a == b)
        return;
    
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
}