#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
    string str; cin.ignore(); getline(cin, str);
    
    int pos, val[26];
    bool chk[26]; for (int i = 0; i < 26; i++) chk[i] = false;
    for (char c: str) {
        pos = c - 'A';
        if ((0 <= pos && pos < 26) && !chk[pos]) {
            cin >> val[pos];
            chk[pos] = true;
        }
    }
    
    double a, b;
    stack<double> s;
    for (char c: str) {
        if (65 <= (int)c && (int)c <= 90) {
            s.push((double)val[c - 'A']);
        } else {
            b = s.top(); s.pop();
            a = s.top(); s.pop();
            switch(c) {
                case '+':
                    s.push(a + b);
                    break;
                case '-':
                    s.push(a - b);
                    break;
                case '*':
                    s.push(a * b);
                    break;
                case '/':
                    s.push(a / b);
                    break;
                default:
                    break;
            }
        }
    }
    
    cout << fixed;
    cout.precision(2);
    cout << s.top();
    
	return 0;
}
