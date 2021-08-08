#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int sz;
int* seg;

bool sorting (pair<int, int> p1, pair<int, int> p2) {
    if (p1.first == p2.first) return p1.second > p2.second;
    else return p1.first < p2.first;
}

void update (int pos, int val) {
    pos += sz;
    seg[pos] = val; pos /= 2;
    while (pos > 0) {
        seg[pos] = max(seg[pos * 2], seg[pos * 2 + 1]);
        pos /= 2;
    }
    return;
}

int query (int n, int nl, int nr, int l, int r) {
    if (r < nl || nr < l) return 0;
    if (l <= nl && nr <= r) return seg[n];
    int mid = (nl + nr + 1) / 2;
    return max(query(n * 2, nl, mid - 1, l, r), query(n * 2 + 1, mid, nr, l, r));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
    sz = 1; while (n > sz) sz *= 2; seg = new int[sz * 2];
    
    vector< pair<int, int> > a;
    int temp; for (int i = 0; i < n; i++) {
        cin >> temp;
        a.push_back(make_pair(temp, i));
    }
    sort(a.begin(), a.end(), sorting);
    
    for (int i = 0; i < sz; i++) update(i, 0);
    
    int val, pos;
    for (int i = 0; i < n; i++) {
        val = a[i].first; pos = a[i].second;
        
        update(pos, query(1, 0, sz - 1, 0, pos - 1) + 1);
    }
    
    cout << seg[1];
    
	return 0;
}
