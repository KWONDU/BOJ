#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int* par;
int* sz;

int find (int x);
void merge (int a, int b);

bool logsort (pair<int, pair<int, int>> p1, pair<int, pair<int, int>> p2) {
    if (p1.second.first != p2.second.first)
        return p1.second.first < p2.second.first;
    return p1.second.second < p2.second.second;
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    par = new int[n];
    for (int i = 0; i < n; i++)
        par[i] = i;
    sz = new int[n];
    for (int i = 0; i < n; i++)
        sz[i] = 1;
    
    vector<pair<int, pair<int, int>>> logs;
    int x1, x2, y;
    for (int i = 0; i < n; i++) {
        cin >> x1 >> x2 >> y;
        logs.push_back(make_pair(i, make_pair(x1, x2)));
    }
    sort(logs.begin(), logs.end(), logsort);
    
    for (int i = 1; i < n; i++)
        if (logs[i].second.first <= logs[i - 1].second.second) {
            merge(logs[i - 1].first, logs[i].first);
            logs[i].second.second = max(logs[i - 1].second.second, logs[i].second.second);
        }
    
    int start, end;
    for (int i = 0; i < q; i++) {
        cin >> start >> end;
        if (find(start - 1) == find(end - 1))
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