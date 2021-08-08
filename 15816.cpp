#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1e6;

int N, M, Q[MAX + 1], cmd[MAX + 1][3];
vector<int> quest;

int seg[1<<22 + 1];

int idx (int val) {
    return lower_bound(quest.begin(), quest.end(), val) - quest.begin();
}

int idxR (int val) {
    return upper_bound(quest.begin(), quest.end(), val) - quest.begin() - 1;
}

void update (int node, int left, int right, int updateIdx, int val) {
    if (updateIdx < left || right < updateIdx) return;
    else if (updateIdx == left && right == updateIdx) {
        seg[node] = val;
        return;
    }
    
    int mid = (left + right) / 2;
    update(node * 2, left, mid, updateIdx, val);
    update(node * 2 + 1, mid + 1, right, updateIdx, val);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
    return;
}

int query (int node, int left, int right, int queryLeft, int queryRight) {
    if (queryRight < left || right < queryLeft) return 0;
    else if (queryLeft <= left && right <= queryRight) return seg[node];
    
    int mid = (left + right) / 2;
    return query(node * 2, left, mid, queryLeft, queryRight) + query(node * 2 + 1, mid + 1, right, queryLeft, queryRight);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for (int i = 1; i <= 1<<22; i++) seg[i] = 0;
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> Q[i];
        quest.push_back(Q[i]);
    }
    cin >> M;
    for (int i = 1; i <= M; i++) {
        cin >> cmd[i][0];
        if (cmd[i][0] == 1) {
            cin >> cmd[i][1];
            quest.push_back(cmd[i][1]);
        } else cin >> cmd[i][1] >> cmd[i][2];
    }
    
    sort(quest.begin(), quest.end());
    quest.erase(unique(quest.begin(), quest.end()), quest.end());
    
    for (int i = 1; i <= N; i++) update(1, 1, quest.size(), idx(Q[i]) + 1, 1);
    
    for (int i = 1; i <= M; i++) {
        if (cmd[i][0] == 1) update(1, 1, quest.size(), idx(cmd[i][1]) + 1, 1);
        else cout << ((cmd[i][2] - cmd[i][1] + 1) - query(1, 1, quest.size(), idx(cmd[i][1]) + 1, idxR(cmd[i][2]) + 1)) << "\n";
    }
    
    return 0;
}