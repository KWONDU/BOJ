#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct {
    int left, right;
} port;

int main () {
    int n, m, k; cin >> n >> m >> k;
    vector<port> ports(n + 1);
    for (int i = 1; i <= n; i++) cin >> ports[i].left >> ports[i].right;
    vector<char> dir(m);
    for (int i = 0; i < m; i++) cin >> dir[i];
    
    int chk[1000 + 1]; for (int i = 1; i <= n; i++) chk[i] = 0;
    int prev = 1, next = 1;
    while(true) {
        for (int i = 0; i < m; i++) {
            if (dir[i] == 'L') next = ports[next].left;
            else next = ports[next].right;
        }
        chk[prev] = next;
        prev = next;
        
        if (chk[prev] != 0) break;
    }
    
    int temp = 1;
    while (temp != chk[prev]) {
        temp = chk[temp];
        k--;
    }
    
    int period = 0;
    while (true) {
        temp = chk[temp];
        period++;
        if (temp == chk[prev]) break;
    }
    k %= period;
    for (int i = 0; i < k; i++) {
        temp = chk[temp];
    }
    cout << temp;
    
    return 0;
}