#include <iostream>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

typedef long long int ll;
typedef struct Point {
    int idx;
    
    ll x, y, dx, dy;
    Point () {};
    Point (ll x, ll y) : x(x), y(y) {};
    Point operator + (const Point &rhs) const { return Point(x + rhs.x, y + rhs.y); };
    Point operator - (const Point &rhs) const { return Point(x - rhs.x, y - rhs.y); };
    bool operator < (const Point & rhs) const { return (x == rhs.x ? y < rhs.y : x < rhs.x); };
} P;

const int MAX = 2000;

int c, n;
P point[MAX];

void input () {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> point[i].x >> point[i].y;
        point[i].idx = i;
    }
    
    return ;
}

bool comp1 (P p1, P p2) {
    return p1 < p2;
}

bool comp2 (P p1, P p2) {
    if (p1.dy * p2.dx == p1.dx * p2.dy) return (p1.dx * p1.dx + p1.dy * p1.dy > p2.dx * p2.dx + p2.dy * p2.dy);
    else return p1.dy * p2.dx < p1.dx * p2.dy;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> c;
    while (c--) {
        input();
        
        sort(point, point + n, comp1);
        
        for (int i = 0; i < n; i++) {
            point[i].dx = point[i].x - point[0].x;
            point[i].dy = point[i].y - point[0].y;
        }
        
        sort(point + 1, point + n, comp2);
        
        int chkIdx = 1;
        while (chkIdx + 1 < n) {
            if (point[chkIdx].dy * point[chkIdx + 1].dx == point[chkIdx].dx * point[chkIdx + 1].dy) chkIdx ++;
            else break;
        }
        
        cout << point[0].idx << " ";
        for (int i = chkIdx; i >= 1; i--) cout << point[i].idx << " ";
        for (int i = chkIdx + 1; i < n; i++) cout << point[i].idx << " ";
        cout << "\n";
    }
    
    return 0;
}