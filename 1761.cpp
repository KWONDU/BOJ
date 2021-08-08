#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct node {
    int par;
    vector<int> child;
    vector<int> len;
};
struct node* tree;

void setpar (int par, int pos) {
    tree[pos].par = par;
    for (int i: tree[pos].child)
        if (i != par) setpar(pos, i);
}

int* dis;
int* dep;
void setdis_dep (int pos, int d, int depth) {
    dis[pos] = d;
    dep[pos] = depth;
    for (int i = 0; i < tree[pos].child.size(); i++)
        if (tree[pos].child[i] != tree[pos].par)
            setdis_dep(tree[pos].child[i], d + tree[pos].len[i], depth + 1);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    tree = new struct node[n + 1];
    
    int temp1, temp2, temp3;
    for (int i = 0; i < n - 1; i++) {
        cin >> temp1 >> temp2 >> temp3;
        tree[temp1].child.push_back(temp2);
        tree[temp1].len.push_back(temp3);
        tree[temp2].child.push_back(temp1);
        tree[temp2].len.push_back(temp3);
    }
    
    setpar(-1, 1);
    
    dis = new int[n + 1];
    dep = new int[n + 1];
    setdis_dep(1, 0, 0);
    
    int m; cin >> m;
    int a, b;
    int ans;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        ans = dis[a] + dis[b];
        
        while (dep[a] > dep[b]) a = tree[a].par;
        while (dep[a] < dep[b]) b = tree[b].par;
        while (a != b) {
            a = tree[a].par;
            b = tree[b].par;
        }
        
        ans -= dis[a] * 2;
        cout << ans << "\n";
        
    }
    
    return 0;
}