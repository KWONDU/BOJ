#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

int T, n, x, y;
vector<pair<int, int>> v;
vector<int> yPos;

long long int seg[1<<18];

void update (int node, int left, int right, int updateIdx) {
    if (updateIdx < left || right < updateIdx) return ;
    else if (left == updateIdx && updateIdx == right) {
        seg[node] ++;
        return ;
    }
    
    int mid = (left + right) / 2;
    update(node * 2, left, mid, updateIdx);
    update(node * 2 + 1, mid + 1, right, updateIdx);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
    
    return ;
}

long long int query (int node, int left, int right, int queryLeft, int queryRight) {
    if (queryRight < left || right < queryLeft) return 0;
    else if (queryLeft <= left && right <= queryRight) return seg[node];
    
    int mid = (left + right) / 2;
    return query(node * 2, left, mid, queryLeft, queryRight) + query(node * 2 + 1, mid + 1, right, queryLeft, queryRight);
}

bool comp (pair<int, int> p1, pair<int, int> p2) {
    return (p1.first == p2.first) ? p1.second > p2.second : p1.first < p2.first;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        memset(seg, 0, sizeof(seg));
        v.clear();
        yPos.clear();
        
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            v.push_back(make_pair(x, y));
            yPos.push_back(y);
        }
        
        sort(v.begin(), v.end(), comp);
        
        sort(yPos.begin(), yPos.end());
        yPos.erase(unique(yPos.begin(), yPos.end()), yPos.end());
        
        int yLen = yPos.size(), pos;
        long long int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            pos = lower_bound(yPos.begin(), yPos.end(), v[i].second) - yPos.begin();
            ans += query(1, 0, yLen - 1, 0, pos);
            update(1, 0, yLen - 1, pos);
        }
        cout << ans << "\n";
    }
    
    return 0;
}