#include <iostream>
#include <string>

using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    char a[50][50], b[50][50];
    for (int i = 0; i < n; i++) {
        string tempstr;
        cin >> tempstr;
        for (int j = 0; j < m; j++)
            a[i][j] = tempstr[j];
    }
    for (int i = 0; i < n; i++) {
        string tempstr;
        cin >> tempstr;
        for (int j = 0; j < m; j++)
            b[i][j] = tempstr[j];
    }
    
    int cnt = 0;
    for (int i = 0; i <= n - 3; i++) {
        for (int j = 0; j <= m - 3; j++) {
            if (a[i][j] == b[i][j])
                continue;
            cnt++;
            for (int x = i; x < i + 3; x++)
                for (int y = j; y < j + 3; y++) {
                    if (a[x][y] == '0')
                        a[x][y] = '1';
                    else
                        a[x][y] = '0';
                }
        }
    }
    
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++)
            if (a[x][y] != b[x][y]) {
                cout << "-1";
                return 0;
            }
    }
    
    cout << cnt;
    
    return 0;
}