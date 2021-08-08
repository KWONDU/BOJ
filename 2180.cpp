#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int mod = 40000;

bool sorting (pair <int, int> p1, pair <int, int> p2) {
    return (p1.second * p2.first) < (p1.first * p2.second);
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int mintime = 0;
    
    int n;
    cin >> n;
    int* a = new int[n];
    int* b = new int[n];
    bool* chk = new bool[n];
    for (int i  = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        
        if (b[i] == 0)
            chk[i] = false;
        else if (a[i] == 0) {
            chk[i] = false;
            mintime += b[i];
            mintime %= mod;
        }
        else
            chk[i] = true;
    }
    
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
        if (chk[i])
            v.push_back(make_pair(a[i], b[i]));
    sort(v.begin(), v.end(), sorting);
    
    int temptime = 0;
    for (auto i : v) {
        int temp = (i.first * temptime + i.second) % mod;
        temptime += temp;
        temptime %= mod;
    }
    
    cout << (mintime + temptime) % mod;
}