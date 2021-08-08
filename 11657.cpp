#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define INF 1<<30

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m; cin >> n >> m;
    vector< pair<int, long long int> > city[500 + 1];
    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        city[a].push_back({b, c});
    }
    
    long long int t[500 + 1];
    for (int i = 1; i <= n; i++) t[i] = INF;
    t[1] = 0;
    
    bool negative = false;
    for (int i = 1; i <= n; i++) {
        for (int from = 1; from <= n; from++) {
            if (t[from] == INF) continue;
            
            for (pair<int, long long int> f: city[from]) {
                int to = f.first;
                long long int timecost = f.second;
                if (t[from] + timecost < t[to]) {
                    if (i == n) negative = true;
                    t[to] = t[from] + timecost;
                }
            }
        }
    }
    
    if (negative) {
        cout << "-1";
        return 0;
    }
    
    for (int i = 2; i <= n; i++) {
        if (t[i] == INF) cout << "-1\n";
        else cout << t[i] << "\n";
    }
    
    return 0;
}