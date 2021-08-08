#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <queue>

using namespace std;

typedef long long int ll;

struct cmp {
    bool operator() (ll x, ll y) {
        if (abs(x) == abs(y)) return x > y;
        return abs(x) > abs(y);
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    priority_queue<ll, vector<ll>, cmp> pq;
    
    int n, chk; cin >> n;
    while (n--) {
        cin >> chk;
        
        if (chk) pq.push(chk);
        else {
            if (pq.empty()) cout << "0\n";
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
    }
    
    return 0;
}