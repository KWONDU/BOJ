#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;

typedef long long int ll;

struct Point {
    ll x, y;
    Point () {};
    Point (ll x, ll y) : x(x), y(y) {};
    Point operator + (const Point &rhs) const { return Point(x + rhs.x, y + rhs.y); };
    Point operator - (const Point &rhs) const { return Point(x - rhs.x, y - rhs.y); };
    bool operator < (const Point &rhs) const { return x != rhs.x ? x < rhs.x : y < rhs.y; };
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

int N, L;
Point B[1000];
vector<int> ch;

bool comp (const Point &p1, const Point &p2) {
    return p1 < p2;
}

double dist (const Point &p1, const Point &p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

void input () {
    cin >> N >> L;
    for (int i = 0; i < N; i++) cin >> B[i].x >> B[i].y;
    
    return ;
}

void convexHull () {
    sort(B, B + N, comp);
    
    stack<int> lower, upper;
    
    for (int i = 0; i < N; i++) {
        while (lower.size() >= 2) {
            int comp2 = lower.top(); lower.pop();
            int comp1 = lower.top(); lower.pop();
            lower.push(comp1); lower.push(comp2);
            if (cross(B[comp1], B[comp2], B[i]) > 0) {
                lower.push(i);
                break ;
            } else lower.pop();
        }
        if (lower.size() < 2) lower.push(i);
    }
    
    for (int i = N - 1; i >= 0; i--) {
        while (upper.size() >= 2) {
            int comp2 = upper.top(); upper.pop();
            int comp1 = upper.top(); upper.pop();
            upper.push(comp1); upper.push(comp2);
            if (cross(B[comp1], B[comp2], B[i]) > 0) {
                upper.push(i);
                break ;
            } else upper.pop();
        }
        if (upper.size() < 2) upper.push(i);
    }
    
    while (!upper.empty()) {
        ch.push_back(upper.top()); upper.pop();
    }
    
    lower.pop();
    while (lower.size() > 1) {
        ch.push_back(lower.top()); lower.pop();
    }
    lower.pop();
    
    return ;
}

void output () {
    double totalLen = 0;
    for (int i = 0; i < ch.size(); i++) {
        totalLen += dist(B[ch[i]], B[ch[(i + 1) % ch.size()]]);
    }
    totalLen += 2 * M_PI * L;
    
    cout << fixed;
    cout.precision(0);
    cout << totalLen;
    
    return ;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    convexHull();
    output();

    return 0;
}