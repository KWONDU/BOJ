#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

typedef long long int ll;
ll* seg;
int sz = 0;

int power2 (int factor) {
    if (factor == 0) return 1;
    return 2 * power2(factor - 1);
}
void update (int pos, ll val);
ll query (int pos, int nl, int nr, int l, int r);

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    int temp_n = n; while (temp_n > 0) {
        temp_n /= 2;
        sz++;
    }
    sz = power2(sz);
    
    seg = new ll[sz * 2];
    for (int i = 0; i < sz * 2; i++) seg[i] = 0;
    for (int i = 0; i < n; i++) cin >> seg[sz + i];
    for (int i = sz - 1; i > 0; i--) seg[i] = seg[i * 2] + seg[i * 2 + 1];
    
    int a, b; ll c;
    for (int i = 0; i < m + k; i++) {
        cin >> a >> b >> c;
        
        if (a == 1) {
            update(b - 1, c);
        } else {
            cout << query(1, 0, sz - 1, b - 1, c - 1) << "\n";
        }
    }
    
    return 0;
}

void update (int pos, ll val) {
    pos += sz;
    seg[pos] = val; pos /= 2;
    while (pos > 0) {
        seg[pos] = seg[pos * 2] + seg[pos * 2 + 1];
        pos /= 2;
    }
    return;
}

ll query (int pos, int nl, int nr, int l, int r) {
    if (nr < l || r < nl) return 0;
    if (l <= nl && nr <= r) return seg[pos];
    int mid = (nl + nr + 1) / 2;
    return query(pos * 2, nl, mid - 1, l, r) + query(pos * 2 + 1, mid, nr, l, r);
}