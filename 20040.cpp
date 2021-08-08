#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int* par;
int* sz;

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
    
    int temp1, temp2;
    for (int i = 1; i <= m; i++) {
        cin >> temp1 >> temp2;
        
        if (find(temp1) == find(temp2)) {
            cout << i;
            return 0;
        }
        merge(temp1, temp2);
    }
    cout << "0";
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