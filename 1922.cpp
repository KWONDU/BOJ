#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int* par;
int* sz;

typedef struct {
    int a, b, c;
} link;

bool computersort (link l1, link l2) {
    return l1.c < l2.c;
}

int find (int x);
void merge (int a, int b);

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    par = new int[n];
    for (int i = 0; i < n; i++)
        par[i] = i;
    sz = new int[n];
    for (int i = 0; i < n; i++)
        sz[i] = 1;
    
    vector<link> computer;
    link templink;
    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        templink.a = a;
        templink.b = b;
        templink.c = c;
        computer.push_back(templink);
    }
    sort(computer.begin(), computer.end(), computersort);
    
    int mincost = 0;
    for (int i = 0; i < m; i++) {
        if (find(computer[i].a) == find(computer[i].b))
            continue;
        
        merge(computer[i].a, computer[i].b);
        mincost += computer[i].c;
    }
    cout << mincost;
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