#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

typedef long long int ll;

struct Point {
    ll x, y;
    Point () {};
    Point (ll x, ll y) : x(x), y(y) {};
    Point operator + (const Point &rhs) const { return Point(x + rhs.x, y + rhs.y); };
    Point operator - (const Point &rhs) const { return Point(x - rhs.x, y - rhs.y); };
    bool operator < (const Point &rhs) const { return x != rhs.x ? x < rhs.x : y < rhs.y; };
    bool operator == (const Point &rhs) const { return x == rhs.x && y == rhs.y; };
};

ll cross (const Point &p1, const Point &p2) {
    ll ret = p1.x * p2.y - p1.y * p2.x;
    return ret == 0 ? 0 : ret / abs(ret);
}

ll cross (const Point &p1, const Point &p2, const Point &p3) {
    return cross(p2 - p1, p3 - p1);
}

bool disjoint (ll l1, ll r1, ll l2, ll r2) {
    if (l1 > r1) swap(l1, r1);
    if (l2 > r2) swap(l2, r2);
    return r1 < l2 || l1 > r2;
}

bool intersect (Point p11, Point p12, Point p21, Point p22) {
    ll c1 = cross(p11, p12, p21) * cross(p11, p12, p22);
    ll c2 = cross(p21, p22, p11) * cross(p21, p22, p12);
    if (c1 == 0 && c2 == 0) return !disjoint(p11.x, p12.x, p21.x, p22.x) && !disjoint(p11.y, p12.y, p21.y, p22.y);
    else return c1 <= 0 && c2 <= 0;
}

int N;
Point ver[10000], Daeyeon, Yeonghun, Beomjin;

bool between (Point l, Point r, Point p) {
    ll lx = l.x, ly = l.y, rx = r.x, ry = r.y;
    if (lx > rx) swap(lx, rx);
    if (ly > ry) swap(ly, ry);
    return lx <= p.x && p.x <= rx && ly <= p.y && p.y <= ry;
}

void input () {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> ver[i].x >> ver[i].y;
    cin >> Daeyeon.x >> Daeyeon.y;
    cin >> Yeonghun.x >> Yeonghun.y;
    cin >> Beomjin.x >> Beomjin.y;
    
    return ;
}

bool alive (Point s) {
    Point e = Point(s.x + 1e9 + 1, s.y + 1);
    
    int intersectCnt = 0;
    bool borderChk = false;
    for (int i = 0; i < N; i++) {
        Point p1 = ver[i], p2 = ver[(i + 1) % N];
        
        if (intersect(s, e, p1, p2)) intersectCnt ++;
        
        if (cross(p1, p2, s) == 0 && between(p1, p2, s)) {
            borderChk = true;
            break;
        }
    }
    
    if (borderChk) return true;
    else return (intersectCnt % 2 == 0 ? false : true);
}

void output () {
    cout << (alive(Daeyeon) ? "1\n" : "0\n");
    cout << (alive(Yeonghun) ? "1\n" : "0\n");
    cout << (alive(Beomjin) ? "1" : "0");
    
    return ;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    output();

    return 0;
}