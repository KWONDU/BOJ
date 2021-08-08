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
    int* pre = new int[n + 1]; pre[0] = 0;
    int temp;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        pre[i] = pre[i - 1] + temp;
    }
    
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        cout << pre[b] - pre[a - 1] << "\n";
    }
}