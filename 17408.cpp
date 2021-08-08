#include <iostream>
#include <algorithm>

using namespace std;

int N, M, A, chk;
pair<int, int> seg[1<<18];

pair<int, int> cal (pair<int, int> p1, pair<int, int> p2) {
    int tempArr[4];
    tempArr[0] = p1.first;
    tempArr[1] = p1.second;
    tempArr[2] = p2.first;
    tempArr[3] = p2.second;
    sort(tempArr, tempArr + 4);
    return make_pair(tempArr[3], tempArr[2]);
}

void update (int node, int left, int right, int updateIdx, int val) {
    if (updateIdx < left || right < updateIdx) return ;
    if (left == updateIdx && updateIdx == right) {
        seg[node].first = val;
        return ;
    }
    
    int mid = (left + right) / 2;
    update(node * 2, left, mid, updateIdx, val);
    update(node * 2 + 1, mid + 1, right, updateIdx, val);
    seg[node] = cal(seg[node * 2], seg[node * 2 + 1]);
    
    return ;
}

pair<int, int> query (int node, int left, int right, int queryLeft, int queryRight) {
    if (queryRight < left || right < queryLeft) return make_pair(0, 0);
    else if (queryLeft <= left && right <= queryRight) return seg[node];
    
    int mid = (left + right) / 2;
    pair<int, int> p1 = query(node * 2, left, mid, queryLeft, queryRight);
    pair<int, int> p2 = query(node * 2 + 1, mid + 1, right, queryLeft, queryRight);
    
    return cal(p1, p2);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for (int i = 1; i <= 1<<18; i++) seg[i] = make_pair(0, 0);
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A;
        update(1, 1, N, i, A);
    }
    cin >> M;
    while (M--) {
        cin >> chk;
        switch (chk) {
            case 1 :
                int i, v;
                cin >> i >> v;
                update(1, 1, N, i, v);
                break;
            case 2 :
                int l, r;
                cin >> l >> r;
                pair<int, int> p = query(1, 1, N, l, r);
                cout << (p.first + p.second) << "\n";
                break;
        }
    }
    
    return 0;
}