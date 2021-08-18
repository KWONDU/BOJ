#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

const double INF = (10000 + 10000) * sqrt(2) + 1;

struct Point {
    double x, y;
    Point () {};
    Point (double x, double y) : x(x), y(y) {};
    Point operator + (const Point &rhs) const { return Point(x + rhs.x, y + rhs.y); };
    Point operator - (const Point &rhs) const { return Point(x - rhs.x, y - rhs.y); };
    bool operator < (const Point &rhs) const { return x != rhs.x ? x < rhs.x : y < rhs.y; };
};

double cross (const Point &p1, const Point &p2) {
    double ret = p1.x * p2.y - p1.y * p2.x;
    return ret == 0 ? 0 : ret / abs(ret);
}

double cross (const Point &p1, const Point &p2, const Point &p3) {
    return cross(p2 - p1, p3 - p1);
}

int t, n;
Point ver[100];
vector<int> ch;

bool comp (const Point &p1, const Point &p2) {
    return p1 < p2;
}

bool input () {
    cin >> n;
    if (n == 0) return false;
    for (int i = 0; i < n; i++) cin >> ver[i].x >> ver[i].y;
    return true;
}

void convexHull () {
    sort(ver, ver + n, comp);
    ch.clear();
    
    stack<int> lower, upper;
    
    for (int i = 0; i < n; i++) {
        while (lower.size() >= 2) {
            int comp2 = lower.top(); lower.pop();
            int comp1 = lower.top(); lower.pop();
            lower.push(comp1); lower.push(comp2);
            if (cross(ver[comp1], ver[comp2], ver[i]) >= 0) {
                lower.push(i);
                break ;
            } else lower.pop();
        }
        if (lower.size() < 2) lower.push(i);
    }
    
    for (int i = n - 1; i >= 0; i--) {
        while (upper.size() >= 2) {
            int comp2 = upper.top(); upper.pop();
            int comp1 = upper.top(); upper.pop();
            upper.push(comp1); upper.push(comp2);
            if (cross(ver[comp1], ver[comp2], ver[i]) >= 0) {
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
    double m, k, n, ans = INF;
    for (int i = 0; i < ch.size(); i++) {
        Point p1 = ver[ch[i]], p2 = ver[ch[(i + 1) % ch.size()]];
        
        // (m)x + (k)y + (n) = 0
        if (p1.x == p2.x) {
            // (1)x + (0)y + (n) = 0
            m = 1;
            k = 0;
            n = -p1.x;
        } else {
            // (m)x + (-1)y + (n) = 0
            m = (p1.y - p2.y) / (p1.x - p2.x);
            k = -1;
            n = (p1.x * p2.y - p1.y * p2.x) / (p1.x - p2.x);
        }
        
        double a, b, len = 0;
        for (int j = 0; j < ch.size(); j++) {
            a = ver[ch[j]].x, b = ver[ch[j]].y;
            len = max(len, abs(m * a + k * b + n) / sqrt(m * m + k * k));
        }
        
        ans = min(ans, len);
    }
    
    ans = ceil(ans * 100) / 100;
    cout << "Case " << t << ": " << ans << "\n";
    
    return ;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout << fixed;
    cout.precision(2);
    t = 0;
    
    while (++t) {
        if (!input()) break;
        
        convexHull();
        output();
    }

    return 0;
}