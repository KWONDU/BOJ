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
        v.push_back(temp);
    }
    
    int maxheight = v[0];
    int cnt = 0;
    int maxcnt = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] > maxheight) {
            maxheight = v[i];
            maxcnt = max(maxcnt, cnt);
            cnt = 0;
        }
        else
            cnt++;
    }
    maxcnt = max(maxcnt, cnt);
    
    cout << maxcnt;
}