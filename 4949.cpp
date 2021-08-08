#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    while (true) {
        string str;
        getline(cin, str);
        if (str == ".") break;
        
        stack<char> s;
        bool chk = true;
        for (char c: str) {
            if (c == '(' || c == '[') {
                s.push(c);
            } else if (c == ')') {
                if (!s.empty() && s.top() == '(') {
                    s.pop();
                } else {
                    chk = false;
                    break;
                }
            } else if (c == ']') {
                if (!s.empty() && s.top() == '[') {
                    s.pop();
                } else {
                    chk = false;
                    break;
                }
            }
        }
        if (s.empty() && chk)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    
	return 0;
}
