#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int chk[10001];
vector<int> num;

vector<int> sequence;
void n_and_m (int len) {
    if (len == m) {
        for (int i = 0; i < len; i++)
            cout << sequence[i] << " ";
        cout << "\n";
        return;
    }
    
    for (int i = 0; i < num.size(); i++) {
        sequence.push_back(num[i]);
        n_and_m(len + 1);
        sequence.pop_back();
    }
    return;
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> n >> m;
    fill_n(chk, 10001, 0);
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        chk[temp]++;
    }
    
    for (int i = 0; i <= 10000; i++)
        if (chk[i] != 0)
            num.push_back(i);
    sort(num.begin(), num.end());
    
    n_and_m(0);
    return 0;
}