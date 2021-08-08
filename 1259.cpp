#include <iostream>
#include <string>

using namespace std;

string s;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (true) {
        cin >> s;
        if (s == "0") break;

        bool flag = true;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != s[s.length() - 1 - i]) {
                flag = false;
                break;
            }
        }

        if (flag) cout << "yes\n";
        else cout << "no\n";
    }
    
    return 0;
}