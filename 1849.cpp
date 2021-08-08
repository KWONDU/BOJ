#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

const int sz = 1<<17;
int seg[sz * 2];

void update (int pos, int val) {
    pos += sz;
    seg[pos] = val; pos /= 2;
    while (pos > 0) {
        seg[pos] = seg[pos * 2] + seg[pos * 2 + 1];
        pos /= 2;
    }
    return;
}

int query (int n, int nl, int nr, int chkval) {
    if (nl == nr) return nl;
    int mid = (nl + nr + 1) / 2;
    if (seg[n * 2] >= chkval) return query(n * 2, nl, mid - 1, chkval);
    else return query(n * 2 + 1, mid, nr, chkval - seg[n * 2]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
    int a[100000 + 1]; for (int i = 1; i <= n; i++) cin >> a[i];
    
    for (int i = 1; i <= n; i++) update(i, 1);
    
    int ans[100000 + 1];
    for (int num = 1; num <= n; num++) {
        int pos = query(1, 0, sz - 1, a[num] + 1);
        ans[pos] = num;
        update(pos, 0);
    }
    
    for (int i = 1; i <= n; i++) cout << ans[i] << "\n";
    
	return 0;
}
