#include <iostream>
#include <deque>
#include <string>
#include <vector>

using namespace std;

int T, n;
string p, tempStr;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;

    while (T--) {
        deque<int> d;
        cin >> p >> n;

        cin >> tempStr;
        vector<int> x;

        int tempInt = 0;
        for (char c : tempStr) {
            if (c == '[') continue;
            else if (c == ',' || c == ']') {
                x.push_back(tempInt);
                tempInt = 0;
            } else {
                tempInt = (tempInt * 10) + (c - '0');
            }
        }

        for (int i = 0; i < n; i++) d.push_back(x[i]);

        bool pos = true, errChk = false;
        for (int i = 0; i < p.length(); i++) {
            if (p[i] == 'R') pos = !pos;
            else if (p[i] == 'D') {
                if (d.empty()) {
                    errChk = true;
                    break;
                }

                if (pos) d.pop_front();
                else d.pop_back();
            }
        }

        if (errChk) cout << "error\n";
        else {
            cout << "[";
            while (d.size() > 1) {
                if (pos) {
                    cout << d.front() << ",";
                    d.pop_front();
                } else {
                    cout << d.back() << ",";
                    d.pop_back();
                }
            }

            if (d.size() == 1) {
                if (pos) cout << d.front() << "]\n";
                else cout << d.back() << "]\n";
            } else cout << "]\n";
        }
    }

    return 0;
}