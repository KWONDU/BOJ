#include <iostream>
#include <vector>

using namespace std;

int N, W;
vector<pair<int, int>> event;

int dp[1000 + 1][1000 + 1];

int max (int n1, int n2) {
    return n1 > n2 ? n1 : n2;
}

int cal (int pos1, int pos2) {
    int nxt = max(pos1, pos2) + 1;
    if (nxt > W) return dp[pos1][pos2] = 0;
    
    if (dp[pos1][pos2] != -1) return dp[pos1][pos2];
    
    pair<int, int> car1 = event[pos1];
    if (pos1 == 0) car1 = make_pair(1, 1);
    pair<int, int> car2 = event[pos2];
    if (pos2 == 0) car2 = make_pair(N, N);
    
    int dis1 = abs(event[nxt].first - car1.first) + abs(event[nxt].second - car1.second);
    int dis2 = abs(event[nxt].first - car2.first) + abs(event[nxt].second - car2.second);
    
    if (cal(nxt, pos2) + dis1 < cal(pos1, nxt) + dis2) {
        car1 = make_pair(event[nxt].first, event[nxt].second);
        return dp[pos1][pos2] = dp[nxt][pos2] + dis1;
    } else {
        car2 = make_pair(event[nxt].first, event[nxt].second);
        return dp[pos1][pos2] = dp[pos1][nxt] + dis2;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> W;
    event.push_back(make_pair(-1, -1));
    for (int i = 0; i < W; i++) {
        int x, y;
        cin >> x >> y;
        event.push_back(make_pair(x, y));
    }
    
    for (int i = 0; i <= W; i++)
        for (int j = 0; j <= W; j++) dp[i][j] = -1;
    
    cout << cal(0, 0) << "\n";
    
    int chk1 = 0, chk2 = 0;
    while (true) {
        int chk = max(chk1, chk2) + 1;
        if (chk > W) break;
        
        pair<int, int> cur = event[chk];
        pair<int, int> c1 = event[chk1];
        if (chk1 == 0) c1 = make_pair(1, 1);
        pair<int, int> c2 = event[chk2];
        if (chk2 == 0) c2 = make_pair(N, N);
        
        int d1 = abs(cur.first - c1.first) + abs(cur.second - c1.second);
        int d2 = abs(cur.first - c2.first) + abs(cur.second - c2.second);
        
        if (dp[chk][chk2] + d1 < dp[chk1][chk] + d2) {
            chk1 = chk;
            cout << "1\n";
        } else {
            chk2 = chk;
            cout << "2\n";
        }
    }
    
    return  0;
}