#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    int arr[100][100];
    int temp;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> temp;
            arr[i][j] = temp;
        }
    
    int cnt = 0;
    int lastpos = -1;
    for (int i = 0; i < n; i++) {
        for (int j = m - 1; j >= 0; j--)
            if (arr[i][j] == 1) {
                lastpos = j;
                break;
            }
        if (lastpos == -1)
            continue;
        
        for (int j = i + 1; j < n; j++) {
            for (int k = lastpos; k < m; k++)
                if (arr[j][k] == 1) {
                    arr[j][k] = 0;
                    lastpos = k;
                }
        }
        lastpos = -1;
        cnt++;
    }
    
    cout << cnt;
}