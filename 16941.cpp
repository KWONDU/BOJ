#include <iostream>
#include <memory.h>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 10;

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
    //cout << p1.x << " " << p1.y << " / " << p2.x << " " << p2.y <<  " : " << ret << endl;
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

int N, ans[MAX];
vector<P> R, S;

void input () {
    cin >> N;
    int temp1, temp2;
    for (int i = 0; i < N; i++) {
        cin >> temp1 >> temp2;
        R.push_back(P(temp1, temp2));
    }
    for (int i = 0; i < N; i++) {
        cin >> temp1 >> temp2;
        S.push_back(P(temp1, temp2));
    }
    
    return ;
}

bool fac (int curShelter, int robotPos) {
    if (robotPos == N) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) continue;
                if (intersect(R[ans[i]], S[i], R[ans[j]], S[j])) return false;
            }
        }
        return true;
    } else if (ans[curShelter] != -1) return false;
    
    ans[curShelter] = robotPos;
    for (int nxtShelter = 0; nxtShelter < N; nxtShelter++) {
        if (!fac(nxtShelter, robotPos + 1)) continue;
        else return true;
    }
    
    ans[curShelter] = -1;
    return false;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    
    //cout << intersect(P(3, 2), P(12, 9), P(2, 9), P(4, 3)) << endl;
    
    memset(ans, -1, sizeof(ans));
    for (int i = 0; i < N; i++) {
        if (fac(i, 0)) {
            for (int rPos = 1; rPos <= N; rPos++) {
                for (int sPos = 0; sPos < N; sPos++) {
                    if (ans[sPos] + 1 == rPos) cout << (sPos + 1) << "\n";
                }
            }
            
            return 0;
        }
    }

    return 0;
}