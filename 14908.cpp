#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare (pair <double, int> p1, pair <double, int> p2) {
    if (p1.first == p2.first)
        return p1.second < p2.second;
    
    return p1.first > p2.first;
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    double* t = new double[n];
    double* s = new double[n];
    for (int i = 0; i < n; i++)
        cin >> t[i] >> s[i];
    
    vector<pair<double, int>> v;
    for (int i = 0; i < n; i++)
        v.push_back(make_pair((s[i] / t[i]), i));
    sort(v.begin(), v.end(), compare);
    
    for (int i = 0; i < n; i++)
        cout << (v[i].second + 1) << " ";
}