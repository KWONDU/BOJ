#include <iostream>
#include <string>
#include <stack>

using namespace std;

int N, X;
string cmd;
stack<int> st;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    while (N--) {
        cin >> cmd;
        if (cmd == "push") {
            cin >> X;
            st.push(X);
        } else if (cmd == "pop") {
            cout << st.top() << "\n";
            st.pop();
        } else if (cmd == "size") {
            cout << st.size() << "\n";
        } else if (cmd == "empty") {
            if (st.empty()) cout << "1\n";
            else cout << "0\n";
        } else {
            if (st.empty()) cout << "-1\n";
            else cout << st.top() << "\n";
        }
    }

    return 0;
}