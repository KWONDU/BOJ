#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int N;
stack<int> st;
vector<char> v;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    int pos = 1;
    bool chk = true;
    while (pos <= N || !st.empty()) {
        int num;
        cin >> num;

        if (st.empty()) {
            while (pos <= num) {
                st.push(pos);
                v.push_back('+');
                pos++;
            }
            st.pop();
            v.push_back('-');
        } else if (st.top() == num) {
            st.pop();
            v.push_back('-');
        } else if (st.top() < num) {
            while (pos <= num) {
                st.push(pos);
                v.push_back('+');
                pos++;
            }
            st.pop();
            v.push_back('-');
        } else {
            chk = false;
            break;
        }
    }

    if (chk) {
        for (char c : v) cout << c << "\n";
    } else cout << "NO";

    return 0;
}