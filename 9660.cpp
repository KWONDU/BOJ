#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    long long int n; cin >> n;
    bool dp[7] = {false, true, false, true, true, true, true};
    
    if (dp[n % 7]) cout << "SK";
    else cout << "CY";
    
    return 0;
}