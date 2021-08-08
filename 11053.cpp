#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    int a[1000];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int len[1000];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        len[i] = 1;
        for (int j =  0; j < i; j++)
            if (a[i] > a[j])
                len[i] = max(len[i], len[j] + 1);
        ans = max(ans, len[i]);
    }
    
    cout << ans;
}