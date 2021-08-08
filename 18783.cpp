#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m, k; cin >> n >> m >> k;
    int table[100000 + 1][30];
    
    int arr[100000 + 1]; for (int i = 1; i <= n; i++) arr[i] = i;
    int l, r;
    for (int i = 0; i < m; i++) {
        cin >> l >> r;
        int first = l, second = r;
        while (first < second) {
            int temp = arr[first];
            arr[first] = arr[second];
            arr[second] = temp;
            first++; second--;
        }
    }
    
    for (int i = 1; i <= n; i++) table[i][0] = arr[i];
    for (int j = 1; j < 30; j++)
        for (int i = 1; i <= n; i++)
            table[i][j] = table[table[i][j - 1]][j - 1];
    
    int ans[100000 + 1]; for (int i = 1; i <= n; i++) ans[i] = i;
    for (int j = 29; j >= 0; j--) {
        int powertwo = 1 << j;
        if (k < powertwo) continue;
        k -= powertwo;
        
        for (int i = 1; i <= n; i++)
            ans[i] = table[ans[i]][j];
    }
    
    for (int i = 1; i <= n; i++) cout << ans[i] << "\n";
    
    return 0;
}