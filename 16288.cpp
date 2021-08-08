#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> v[100];
    int temp;
    bool chk = false;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        for (int j = 0; j < k; j++)
            if (v[j].empty() || v[j].back() < temp) {
                v[j].push_back(temp);
                chk = true;
                break;
            }
        
        if (!chk) {
            cout << "NO";
            return 0;
        }
        chk = false;
    }
    
    cout << "YES";
}