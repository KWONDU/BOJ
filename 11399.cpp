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
    
    sort(v.begin(), v.end());
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += v[i] * (n - i);
    }
    
    cout << sum;
}