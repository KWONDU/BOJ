#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

bool* chk;
int* node;
vector<int>* work;

bool dfs (int x) {
    for (int y: work[x]) {
        if (chk[y]) continue;
        
        chk[y] = true;
        if (node[y] == 0 || dfs(node[y])) {
            node[y] = x;
            return true;
        }
    }
    return false;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m, k; cin >> n >> m >> k;
    chk = new bool[m + 1];
    node = new int[m + 1];
    work = new vector<int>[n + 1];
    
    for (int i = 1; i <= m; i++) node[i] = 0;
    int temp1, temp2;
    for (int i = 1; i <= n; i++) {
        cin >> temp1;
        for (int j = 0; j < temp1; j++) {
            cin >> temp2;
            work[i].push_back(temp2);
        }
    }
    
    int cnt1 = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) chk[j] = false;
        if (dfs(i)) cnt1++;
    }
    
    int cnt2 = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) chk[j] = false;
        if (dfs(i)) cnt2++;
        
        if (cnt2 == k) break;
    }
    
    cout << cnt1 + cnt2;
    
    return 0;
}