#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    int temp1, temp2;
    for (int i = 0; i < n; i++) {
        cin >> temp1 >> temp2;
        v.push_back(make_pair(temp2, temp1));
    }
    sort(v.begin(), v.end());
    
    int pos = 0;
    int cnt = 1;
    for (int i = 1; i < n; i++)
        if (v[pos].first <= v[i].second) {
            pos = i;
            cnt++;
        }
    
    cout << cnt;
}