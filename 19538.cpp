#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct person {
    vector<int> around;
    int total = 0;
    int cnt = 0;
    bool chk = false;
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    struct person rumor[200000 + 1];
    int temp;
    for (int i = 1; i <= n; i++) {
        while (true) {
            cin >> temp;
            if (temp == 0) break;
            rumor[i].around.push_back(temp);
            rumor[i].total++;
        }
    }
    int t[200000 + 1]; for (int i = 1; i <= n; i++) t[i] = -1;
    
    int m; cin >> m;
    queue< pair<int, int> > q1;
    queue< pair<int, int> > q2;
    for (int i = 0; i < m; i++) {
        cin >> temp;
        q1.push(make_pair(temp, 0));
        t[temp] = 0;
        rumor[temp].chk = true;
    }
    
    while (!q1.empty()) {
        while (!q1.empty()) {
            for (int i: rumor[q1.front().first].around) rumor[i].cnt++;
            for (int i: rumor[q1.front().first].around)
                if (!rumor[i].chk) q2.push(make_pair(i, q1.front().second + 1));
            q1.pop();
        }
        
        while (!q2.empty()) {
            if (!rumor[q2.front().first].chk && 
                rumor[q2.front().first].cnt * 2 >= rumor[q2.front().first].total) {
                q1.push(make_pair(q2.front().first, q2.front().second));
                t[q2.front().first] = q2.front().second;
                rumor[q2.front().first].chk = true;
            }
            q2.pop();
        }
    }
    
    for (int i = 1; i <= n; i++) cout << t[i] << " ";
    
    return 0;
}