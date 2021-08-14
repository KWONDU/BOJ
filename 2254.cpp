#include <iostream>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

const int MAX = 1000;

typedef long long int ll;
typedef struct Point {
    ll x, y;
    Point () {};
    Point (ll x, ll y) : x(x), y(y) {};
    Point operator + (const Point &rhs) const { return Point(x + rhs.x, y + rhs.y); };
    Point operator - (const Point &rhs) const { return Point(x - rhs.x, y - rhs.y); };
    bool operator < ( const Point &rhs) const { return (x == rhs.x ? y < rhs.y : x < rhs.x); };
} P;

ll cross (const P &p1, const P &p2) {
    ll ret = p1.x * p2.y - p1.y * p2.x;
    return (ret == 0 ? ret : ret / abs(ret));
}

ll cross (const P &p1, const P &p2, const P &p3) {
    return cross(p2 - p1, p3 - p1);
}

int N, cnt;
P prison;
vector<P> wall;
bool use[MAX];
vector<int> make, ch;
stack<int> lower, upper;

void input () {
    cin >> N >> prison.x >> prison.y;
    for (int i = 0; i < N; i++) {
        int tempx, tempy;
        cin >> tempx >> tempy;
        wall.push_back(P(tempx, tempy));
    }
    
    return ;
}

bool comp1 (P p1, P p2) {
    return (p1.x == p2.x ? p1.y < p2.y : p1.x < p2.x);
}

bool prisonBetween (P p1, P p2) {
    if ((p1.x <= prison.x && prison.x <= p2.x) && (p1.y <= prison.y && prison.y <= p2.y)) return true;
    else if ((p2.x <= prison.x && prison.x <= p1.x) && (p2.y <= prison.y && prison.y <= p1.y)) return true;
    else return false;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    
    memset(use, false, sizeof(use));
    cnt = 0;
    
    sort(wall.begin(), wall.end(), comp1);
    
    while (true) {
        make.clear();
        ch.clear();
        
        for (int i = 0; i < N; i++)
            if (!use[i]) make.push_back(i);
        if (make.size() == 0) break;
        
        for (int i = 0; i < make.size(); i++) {
            if (lower.size() < 2) lower.push(make[i]);
            else {
                while (lower.size() >= 2) {
                    int comp2 = lower.top();
                    lower.pop();
                    int comp1 = lower.top();
                    lower.pop();
                    lower.push(comp1);
                    lower.push(comp2);
                    if (cross(wall[comp1], wall[comp2], wall[make[i]]) >= 0) {
                        lower.push(make[i]);
                        break;
                    } else lower.pop();
                }
                if (lower.size() < 2) lower.push(make[i]);
            }
        }
        
        for (int i = make.size() - 1; i >= 0; i--) {
            if (upper.size() < 2) upper.push(make[i]);
            else {
                while (upper.size() >= 2) {
                    int comp2 = upper.top();
                    upper.pop();
                    int comp1 = upper.top();
                    upper.pop();
                    upper.push(comp1);
                    upper.push(comp2);
                    if (cross(wall[comp1], wall[comp2], wall[make[i]]) >= 0) {
                        upper.push(make[i]);
                        break;
                    } else upper.pop();
                }
                if (upper.size() < 2) upper.push(make[i]);
            }
        }
        
        while (!upper.empty()) {
            ch.push_back(upper.top());
            upper.pop();
        }
        
        lower.pop();
        while (lower.size() > 1) {
            ch.push_back(lower.top());
            lower.pop();
        }
        lower.pop();
        
        reverse(ch.begin(), ch.end());
        
        bool betweenFlag = false;
        int zeroCnt = 0, elseCnt = 0;
        for (int i = 0; i < ch.size(); i++) {
            int ccw = cross(prison, wall[ch[i]], wall[ch[(i + 1) % ch.size()]]);
            if (ccw == 0) {
                if (prisonBetween(wall[ch[i]], wall[ch[(i + 1) % ch.size()]])) betweenFlag = true;
                else zeroCnt++;
            } else elseCnt += ccw;
        }
        
        if (betweenFlag) break;
        
        if ((zeroCnt != ch.size()) && (abs(elseCnt) == (ch.size() - zeroCnt))) {
            cnt++;
            for (int c : ch) use[c] = true;
        } else break;
    }
    
    cout << cnt;

    return 0;
}