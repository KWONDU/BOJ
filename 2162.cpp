#include <iostream>
#include <memory.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;
typedef struct Point {
    ll x, y;
    Point () {};
    Point (ll x, ll y) : x(x), y(y) {};
    Point operator + (const Point &rhs) const { return Point(x + rhs.x, y + rhs.y); };
    Point operator - (const Point &rhs) const { return Point(x - rhs.x, y - rhs.y); };
    bool operator < (const Point & rhs) const { return (x == rhs.x ? y < rhs.y : x < rhs.x); };
} P;

ll cross (const P &p1, const P &p2) {
    ll ret = p1.x * p2.y - p1.y * p2.x;
    return (ret == 0 ? ret : ret / abs(ret));
}

ll cross (const P &p1, const P &p2, const P &p3) {
    return cross(p2 - p1, p3 - p1);
}

bool disjoint (ll l1, ll r1, ll l2, ll r2) {
    if (l1 > r1) swap(l1, r1);
    if (l2 > r2) swap(l2, r2);
    return (r1 < l2 || l1 > r2);
}

bool intersect (P p11, P p12, P p21, P p22) {
    ll c1 = cross(p11, p12, p21) * cross(p11, p12, p22);
    ll c2 = cross(p21, p22, p11) * cross(p21, p22, p12);
    if (c1 == 0 && c2 == 0) return !disjoint(p11.x, p12.x, p21.x, p22.x) && !disjoint(p11.y, p12.y, p21.y, p22.y);
    else return (c1 <= 0 && c2 <= 0);
}

struct Line {
    P s, e;
    Line () {};
    Line (P s, P e) : s(s), e(e) {};
};

const int MAX = 3000;

int N, group[MAX], group_num;
Line seg[MAX];
vector<int> v[MAX];

void input () {
    int x1, y1, x2, y2;
    
    memset(group, -1, sizeof(group));
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        seg[i] = Line(P(x1, y1), P(x2, y2));
    }
    
    return ;
}

void dfs (int cur) {
    group[cur] = group_num;
    
    for (int nxt : v[cur]) {
        if (group[nxt] == -1) dfs(nxt);
    }
    
    return ;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j && intersect(seg[i].s, seg[i].e, seg[j].s, seg[j].e)) v[i].push_back(j);
        }
    }
    
    for (int i = 0; i < N; i++) {
        if (group[i] == -1) {
            group_num ++;
            dfs(i);
        }
    }
    
    int max_group_cnt = 0;
    for (int n = 1; n <= group_num; n++) {
        int group_cnt = 0;
        for (int i = 0; i < N; i++) if (group[i] == n) group_cnt ++;
        max_group_cnt = max(max_group_cnt, group_cnt);
    }
    cout << group_num << "\n" << max_group_cnt;
    
    return 0;
}