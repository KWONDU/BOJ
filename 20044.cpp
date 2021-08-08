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
    for (int i = 0; i < 2 * n; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    
    sort(v.begin(), v.end());
    int minsum = 2 * v[2 * n - 1];
    int tempsum;
    for (int i = 0; i < n; i++) {
        tempsum = v[i] + v[2 * n - 1 - i];
        if (minsum > tempsum)
            minsum = tempsum;
    }
    
    cout << minsum;
}