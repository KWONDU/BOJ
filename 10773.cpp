#include <iostream>
#include <stack>

using namespace std;

int K;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> K;
    stack<int> st;

    int num;
    while (K--) {
        cin >> num;
        if (num == 0) st.pop();
        else st.push(num);
    }

    int sum = 0;
    while (!st.empty()) {
        sum += st.top();
        st.pop();
    }

    cout << sum;

    return 0;
}