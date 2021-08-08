#include <iostream>
#include <memory.h>
#include <vector>

using namespace std;

int N, C, x, y, Q, flag, A;
vector<int> v[200000 + 1];

int seg[1<<19];

int depth[200000 + 1], idx[200000 + 1][2], cnt;

void dfs (int cur, int d) {
    idx[cur][0] = ++cnt;
    depth[cur] = d;
    for (int nxt : v[cur])
        if (depth[nxt] == 0) dfs(nxt, d + 1);
    idx[cur][1] = cnt;
    
    return ;
}

void update (int node, int left, int right, int updateIdx) {
    if (updateIdx < left || right < updateIdx) return ;
    else if (left == updateIdx && updateIdx == right) {
        seg[node]++;
        return ;
    }
    
    int mid = (left + right) / 2;
    update(node * 2, left, mid, updateIdx);
    update(node * 2 + 1, mid + 1, right, updateIdx);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
    
    return ;
}

int query (int node, int left, int right, int queryLeft, int queryRight) {
    if (queryRight < left || right < queryLeft) return 0;
    else if (queryLeft <= left && right <= queryRight) return seg[node];
    
    int mid = (left + right) / 2;
    return query(node * 2, left, mid, queryLeft, queryRight) + query(node * 2 + 1, mid + 1, right, queryLeft, queryRight);
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    memset(seg, 0, sizeof(seg));
    memset(depth, 0, sizeof(depth));
    
    cin >> N >> C;
    for (int i = 0; i < N - 1; i++) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    cnt = 0;
    dfs(C, 1);
    
    cin >> Q;
    while (Q--) {
        cin >> flag >> A;
        switch (flag) {
            case 1 :
                update(1, 1, N, idx[A][0]);
                break;
            case 2 :
                cout << ((long long int)depth[A] * query(1, 1, N, idx[A][0], idx[A][1])) << "\n";
                break;
        }
    }
    
    return 0;
}