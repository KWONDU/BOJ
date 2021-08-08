#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int x, y, m;
    cin >> x >> y >> m;
    vector<int> loss;
    vector<int> gain;
    int temp;
    for (int i = 0; i < x; i++) {
        cin >> temp;
        loss.push_back(temp);
    }
    for (int i = 0; i < y; i++) {
        cin >> temp;
        gain.push_back(temp);
    }
    
    string s = "";
    
    int life = m;
    int pos = 0;
    for (int i = 0; i < x; i++) {
        life -= loss[i];
        s.append("-" + to_string(i + 1) + "\n");
        
        if (life <= 0) {
            cout << "0";
            return 0;
        }
        
        while (pos < y && life <= m / 2) {
            life += gain[pos];
            s.append(to_string(pos + 1) + "\n");
            pos++;
        }
    }
    
    for (int i = pos; i < y; i++)
        s.append(to_string(i + 1) + "\n");
    
    cout << s;
}