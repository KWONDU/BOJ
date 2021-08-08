#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

typedef struct {
    int start, end, width;
} road;

bool roadsort (road r1, road r2) {
    return r1.width < r2.width;
}

int* par;
int* sz;

int find (int x);
void merge (int a, int b);

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int p, w;
    cin >> p >> w;
    int c, v;
    cin >> c >> v;
    
    par = new int[p];
    sz = new int[p];
    for (int i = 0; i < p; i++) {
        par[i] = i;
        sz[i] = 1;
    }
    
    vector<road> roads;
    road temproad;
    int temp1, temp2, temp3;
    for (int i = 0; i < w; i++) {
        cin >> temp1 >> temp2 >> temp3;
        temproad.start = temp1;
        temproad.end = temp2;
        temproad.width = temp3;
        roads.push_back(temproad);
    }
    sort(roads.begin(), roads.end(), roadsort);
    
    int minwidth = 0;
    for (int i = w - 1; i >= 0; i--) {
        merge(roads[i].start, roads[i].end);
        if (find(c) == find(v)) {
            minwidth = roads[i].width;
            break;
        }
    }
    
    cout << minwidth;
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