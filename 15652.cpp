#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int n, m;
vector<int> v;

void n_and_m (int len) {
    if (len == m) {
        for (int v_ : v)
            cout << v_ << " ";
        cout << "\n";
        return;
    }
    
    for (int i = 1; i <= n; i++)
        if (v.empty() || v.back() <= i) {
            v.push_back(i);
            n_and_m(len + 1);
            v.pop_back();
        }
    return;
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> n >> m;
    n_and_m(0);
}