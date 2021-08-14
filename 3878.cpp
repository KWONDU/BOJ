#include <iostream>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

const int MAX = 100;

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

int T, n, m;
vector<P> black, white;
vector<int> cH[2];

bool comp (P p1, P p2) {
    return (p1.x == p2.x ? p1.y < p2.y : p1.x < p2.x);
}

void input () {
    black.clear(); white.clear();
    cH[0].clear(); cH[1].clear();
    
    cin >> n >> m;
    int tempx, tempy;
    for (int i = 0; i < n; i++) {
        cin >> tempx >> tempy;
        black.push_back(P(tempx, tempy));
    }
    for (int i = 0; i < m; i++) {
        cin >> tempx >> tempy;
        white.push_back(P(tempx, tempy));
    }
    
    return ;
}

stack<int> halfCH (vector<P> arr, int sz) {
    stack<int> st;
    int comp1, comp2;
    for (int i = 0; i < sz; i++) {
        if (st.size() < 2) st.push(i);
        else {
            while (st.size() >= 2) {
                comp2 = st.top(); st.pop();
                comp1 = st.top(); st.pop();
                st.push(comp1); st.push(comp2);
                
                if (cross(arr[comp1], arr[comp2], arr[i]) >= 0) {
                    st.push(i);
                    break;
                } else st.pop();
            }
            if (st.size() < 2) st.push(i);
        }
    }
    
    return st;
}

void makeCH (vector<P> arr, int sz, int flag) {
    stack<int> lower = halfCH(arr, sz);
    reverse(arr.begin(), arr.end());
    stack<int> upper = halfCH(arr, sz);
    
    while (!upper.empty()) {
        cH[flag].push_back(sz - 1 - upper.top()); upper.pop();
    }
    
    lower.pop();
    while (lower.size() > 1) {
        cH[flag].push_back(lower.top()); lower.pop();
    }
    lower.pop();
    
    reverse(cH[flag].begin(), cH[flag].end());
    
    return ;
}

bool pointChk (vector<P> cur, vector<P> op) {
    for (P curPoint : cur) {
        int zeroCnt = 0, elseCnt = 0;
        for (int i = 0; i < op.size(); i++) {
            int ccw = cross(curPoint, op[i], op[(i + 1) % op.size()]);
            if (ccw == 0) zeroCnt++;
            else elseCnt += ccw;
        }
        
        if ((zeroCnt != op.size()) && abs(elseCnt) == (op.size() - zeroCnt)) return false;
    }
    
    return true;
}

bool lineChk (vector<P> v1, vector<P> v2) {
    for (int i = 0; i < v1.size(); i++) {
        for (int j = 0; j < v2.size(); j++) {
            if (intersect(v1[i], v1[(i + 1) % v1.size()], v2[j], v2[(j + 1) % v2.size()])) return false;
        }
    }
    
    return true;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        input();
        
        sort(black.begin(), black.end(), comp);
        sort(white.begin(), white.end(), comp);
        
        makeCH(black, n, 0);
        makeCH(white, m, 1);
        
        //reverse(cH[0].begin(), cH[0].end());
        //reverse(cH[1].begin(), cH[1].end());
        
        vector<P> blackCH, whiteCH;
        for (int i : cH[0]) blackCH.push_back(black[i]);
        for (int i : cH[1]) whiteCH.push_back(white[i]);
        
        bool ret = true;
        
        ret = ret && pointChk(blackCH, whiteCH);
        ret = ret && pointChk(whiteCH, blackCH);
        
        ret = ret && lineChk(blackCH, whiteCH);
        
        cout << (ret ? "YES\n" : "NO\n");
    }

    return 0;
}