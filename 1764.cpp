#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> hear;
vector<string> see;

int binaryFind(string s) {
    int low = 0;
    int high = hear.size() - 1;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        
        if (hear[mid] < s) low = mid + 1;
        else if (hear[mid] > s) high = mid - 1;
        else return mid;
    }
    
    if (hear[low] == s) return low;
    else return hear.size();
}

int main()
{
    int n, m;
    cin >> n >> m;
    
    string temp;
    
    while (n--) {
        cin >> temp;
        hear.push_back(temp);
    }
    
    while (m--) {
        cin >> temp;
        see.push_back(temp);
    }
    
    sort(hear.begin(), hear.end());
    
    vector<string> ans;
    for (string chk: see) {
        int pos = binaryFind(chk);
        if (pos < hear.size()) ans.push_back(chk);
    }
    
    sort(ans.begin(), ans.end());
    
    cout << ans.size() << "\n";
    for (string a: ans) cout << a << "\n";
    
    return 0;
}