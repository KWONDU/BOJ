#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    int p[100];
    for (int i = 0; i < n; i++) cin >> p[i];
    
    int ans = p[0];
    for (int i = 1; i < n; i++) ans = ans ^ p[i];
    
    if (ans) cout << "koosaga";
    else cout << "cubelover";
    
    return 0;
}