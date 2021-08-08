#include <iostream>
#include <queue>

using namespace std;
typedef long long int ll;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    ll a, b; cin >> a >> b;
    
    queue<pair<ll, int>> q;
    q.push(make_pair(a, 1));
    while (!q.empty()) {
        if (q.front().first == b) break;
        ll temp = q.front().first;
        int tempcnt = q.front().second;
        q.pop();
        
        if (temp * 2 <= b) q.push(make_pair(temp * 2, tempcnt + 1));
        if (temp * 10 + 1 <= b) q.push(make_pair(temp * 10 + 1, tempcnt + 1));
    }
    
    if (q.empty()) cout << "-1";
    else cout << q.front().second;
    
    return 0;
}