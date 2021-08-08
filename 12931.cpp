#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> v;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (temp != 0)
            v.push_back(temp);
    }
    
    int cnt = 0;
    while (!v.empty()) {
        bool chkdiv2 = true;
        for (int i = 0; i < v.size(); i++)
            if (v[i] % 2 == 1) {
                v[i]--;
                cnt++;
                chkdiv2 = false;
                break;
            }
        
        if (chkdiv2) {
            for (int i = 0; i < v.size(); i++)
                v[i] /= 2;
            cnt++;
        }
        
        while (!v.empty() && v.back() == 0)
            v.pop_back();
    }
    
    cout << cnt;
}