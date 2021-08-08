#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long int ll;

const int MAX = 1e5;
bool chk[MAX + 1];

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    for (int i = 0; i <= MAX; i++) chk[i] = false;
    int n, k; cin >> n >> k;
    
    queue<pair<int, int>> q;
    q.push(make_pair(n, 0));
    chk[n] = true;
    while (!q.empty()) {
        if (q.front().first == k) break;
        int temppos = q.front().first;
        int temptime = q.front().second;
        q.pop();
        
        if (0 <= temppos - 1 && temppos - 1 <= MAX && !chk[temppos - 1]) {
            q.push(make_pair(temppos - 1, temptime + 1));
            chk[temppos - 1] = true;
        }
        if (0 <= temppos + 1 && temppos + 1 <= MAX && !chk[temppos + 1]) {
            q.push(make_pair(temppos + 1, temptime + 1));
            chk[temppos + 1] = true;
        }
        if (0 <= temppos * 2 && temppos * 2 <= MAX && !chk[temppos * 2]) {
            q.push(make_pair(temppos * 2, temptime + 1));
            chk[temppos * 2] = true;
        }
    }
    
    int mintime = q.front().second;
    q.pop();
    while (!q.empty()) {
        mintime = min(mintime, q.front().second);
        q.pop();
    }
    cout << mintime;
    
    return 0;
}