#include <iostream>
#include <string>
#include <stack>

using namespace std;

int T;
string line;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    
    while (T--) {
        cin >> line;
        stack<char> st;
        bool chk = true;
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == '(') st.push(line[i]);
            else {
                if (!st.empty() && st.top() == '(') st.pop();
                else {
                    chk = false;
                    break;
                }
            }
        }

        if (!st.empty()) chk = false;

        if (chk) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}