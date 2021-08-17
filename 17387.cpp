#include <iostream>
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

int x1, x2, x3, x4, y1, y2, y3, y4;

void input () {
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    
    return ;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    
    cout << (intersect(P(x1, y1), P(x2, y2), P(x3, y3), P(x4, y4)) ? 1 : 0);
    
    return 0;
}