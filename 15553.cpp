#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<int> t;
    int start, end;
    int temp1, temp2;
    cin >> temp1;
    start = temp1;
    for (int i = 0; i < n - 1; i++) {
        cin >> temp2;
        t.push_back(temp2 - temp1 - 1);
        temp1 = temp2;
    }
    if (n == 1)
        end = temp1;
    else
        end = temp2;
    
    int totaltime = end + 1 - start;
    sort(t.begin(), t.end());
    int temptime = 0;
    for (int i = n - k; i < n - 1; i++)
        temptime += t[i];
    
    cout << (totaltime - temptime);
}