#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int power10 (int exponent) {
    int re = 1;
    for (int i = 0; i < exponent; i++)
        re *= 10;
    return re;
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    vector<pair<int, char>> v;
    string temp;
    char tempchar;
    int tempint;
    bool chk = false;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        for (int j = 0; j < temp.length(); j++) {
            tempchar = temp[j];
            tempint = power10(temp.length() - 1 - j);
            
            for (int i = 0; i < v.size(); i++)
                if (v[i].second == tempchar) {
                    v[i].first += tempint;
                    chk = true;
                    break;
                }
            
            if (!chk)
                v.push_back(make_pair(tempint, tempchar));
            chk = false;
        }
    }
    
    sort(v.begin(), v.end());
        
    int maxsum = 0;
    int num = 9;
    for (int i = v.size() - 1; i >= 0; i--) {
        maxsum += v[i].first * num;
        num--;
    }
        
    cout << maxsum;
}