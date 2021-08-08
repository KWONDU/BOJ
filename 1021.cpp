#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m; cin >> n >> m;
    int* pos = new int[m]; for (int i = 0; i < m; i++) cin >> pos[i];
    
    deque<int> dq;
    for (int i = 1; i <= n; i++) dq.push_back(i);
    
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        int tempcnt = 0, temp;
        while (dq.front() != pos[i]) {
            temp = dq.front();
            dq.pop_front();
            dq.push_back(temp);
            tempcnt++;
        }
        dq.pop_front();
        
        if (tempcnt > dq.size() - tempcnt) {
            tempcnt = dq.size() - tempcnt;
            tempcnt += 1;
        }
        cnt += tempcnt;
    }
    
    cout << cnt;
    
	return 0;
}
