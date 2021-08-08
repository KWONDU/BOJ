#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    int pre[1024 + 1][1024 + 1];
    for (int i = 0; i <= n; i++) pre[i][0] = 0;
    for (int j = 0; j <= n; j++) pre[0][j] = 0;
    
    int temp;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> temp;
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + temp;
        }
    
    int x1, y1, x2, y2;
    for (int i = 0; i < m; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        
        cout << pre[x2][y2] - pre[x2][y1 - 1] - pre[x1 - 1][y2] + pre[x1 - 1][y1 - 1] << "\n";
    }
}