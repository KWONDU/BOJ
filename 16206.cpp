#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int totalnum = 0;
    
    int n, m;
    cin >> n >> m;
    vector<int> div10;
    vector<int> ndiv10;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (temp == 10)
            totalnum++;
        else if (temp > 10 && temp % 10 == 0)
            div10.push_back(temp);
        else if (temp > 10 && temp % 10 != 0)
            ndiv10.push_back(temp);
    }
    
    int tempnum;
    int tempcnt;
    
    sort(div10.begin(), div10.end());
    for (int i = 0; i < div10.size(); i++) {
        if (m == 0)
            break;
        
        tempcnt = div10[i] / 10 - 1;
        tempnum = tempcnt + 1;
        if (m >= tempcnt) {
            totalnum += tempnum;
            m -= tempcnt;
        }
        else {
            totalnum += m;
            m = 0;
        }
    }
    
    for (int i = 0; i < ndiv10.size(); i++) {
        if (m == 0)
            break;
        
        tempcnt = ndiv10[i] / 10;
        tempnum = tempcnt;
        if (m >= tempcnt) {
            totalnum += tempnum;
            m -= tempcnt;
        }
        else {
            totalnum += m;
            m = 0;
        }
    }
    
    cout << totalnum;
}