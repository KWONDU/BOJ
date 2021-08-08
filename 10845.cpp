#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N, X;
string cmd;
queue<int> q;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    while (N--) {
        cin >> cmd;
        if (cmd == "push") {
            cin >> X;
            q.push(X);
        } else if (cmd == "pop") {
            if (q.empty()) cout << "-1\n";
            else {
                cout << q.front() << "\n";
                q.pop();
            }
        } else if (cmd == "size") {
            cout << q.size() << "\n";
        } else if (cmd == "empty") {
            if (q.empty()) cout << "1\n";
            else cout << "0\n";
        } else if (cmd == "front") {
            if (q.empty()) cout << "-1\n";
            else cout << q.front() << "\n";
        } else {
            if (q.empty()) cout << "-1\n";
            else cout << q.back() << "\n";
        }
    }

    return 0;
}