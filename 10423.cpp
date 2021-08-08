#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

typedef struct {
    int u, v, w;
} line;

bool sorting (line l1, line l2) {
    return l1.w < l2.w;
}

int* par;
int* sz;

int n, m, k;
int* elec;

int find (int x);
void merge (int a, int b);

bool chk (line l) {
    bool chk1 = false;
    bool chk2 = false;
    for (int i = 0; i < k; i++) {
        if (find(l.u) == find(elec[i]))
            chk1 = true;
        if (find(l.v) == find(elec[i]))
            chk2 = true;
        
        if (chk1 && chk2)
            return true;
    }
    
    if (find(l.u) == find(l.v))
        return true;
    else
        return false;
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> n >> m >> k;
    
    par = new int[n];
    sz = new int[n];
    for (int i = 0; i < n; i++) {
        par[i] = i;
        sz[i] = 1;
    }
    
    elec = new int[k];
    int temp;
    for (int i = 0; i < k; i++) {
        cin >> temp;
        elec[i] = temp - 1;
    }
    vector<line> lines;
    line templine;
    int temp1, temp2, temp3;
    for (int i = 0; i < m; i++) {
        cin >> temp1 >> temp2 >> temp3;
        templine.u = temp1 - 1;
        templine.v = temp2 - 1;
        templine.w = temp3;
        lines.push_back(templine);
    }
    sort(lines.begin(), lines.end(), sorting);
    
    int mincost = 0;
    for (int i = 0; i < m; i++) {
        if (chk(lines[i]))
            continue;
        
        merge(lines[i].u, lines[i].v);
        mincost += lines[i].w;
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