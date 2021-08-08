#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, s, cnt;
int* arr;

vector<int> v;
void func (int len, int pos) {
    if (v.size() == len) {
        int tempsum = 0;
        for (int i = 0; i < v.size(); i++)
            tempsum += v[i];
        if (tempsum == s)
            cnt++;
        return;
    }
    else if (pos == n)
        return;
    
    v.push_back(arr[pos]);
    func(len, pos + 1);
    v.pop_back();
    func(len, pos + 1);
    return;
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> n >> s;
    arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    cnt = 0;
    for (int len = 1; len <= n; len++)
        func(len, 0);
    cout << cnt;
}