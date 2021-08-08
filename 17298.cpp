#include <iostream>
#include <memory.h>
#include <stack>

using namespace std;

int N, A[1000000], NGE[1000000];
stack<int> st;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];

    memset(NGE, -1, sizeof(NGE));

    st.push(A[N - 1]);
    for (int i = N - 2; i >= 0; i--) {
        while (!st.empty()) {
            if (A[i] < st.top()) {
                NGE[i] = st.top();
                break;
            } else st.pop();
        }
        st.push(A[i]);
    }

    for (int i = 0; i < N; i++) cout << NGE[i] << " ";

    return 0;
}