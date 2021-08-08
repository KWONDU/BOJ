#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int n, m;
int* num;
bool* chk;
vector<int> v;

void n_and_m (int len) {
    if (len == m) {
        for (int v_ : v)
            cout << v_ << " ";
        cout << "\n";
        return;
    }
    
    for (int i = 0; i < n; i++)
        if (!chk[i]) {
            v.push_back(num[i]);
            chk[i] = true;
            n_and_m(len + 1);
            v.pop_back();
            chk[i] = false;
        }
    return;
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> n >> m;
    num = new int[n];
    for (int i = 0; i < n; i++)
        cin >> num[i];
    sort(num, num + n);
    chk = new bool[n];
    fill_n(chk, n, false);
    n_and_m(0);
}