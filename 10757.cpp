#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n1, n2;
string A, B;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> A >> B;

    vector<int> ans;

    int temp = 0;
    for (int i = 0; i < max(A.length(), B.length()); i++) {
        if (i >= A.length()) n1 = 0;
        else n1 = A[A.length() - 1 - i] - '0';

        if (i >= B.length()) n2 = 0;
        else n2 = B[B.length() - 1 - i] - '0';

        if (n1 + n2  + temp >= 10) {
            ans.push_back(n1 + n2 + temp- 10);
            temp = 1;
        } else {
            ans.push_back(n1 + n2 + temp);
            temp = 0;
        }
    }

    if (temp == 1) cout << "1";
    for (int i = 0; i < ans.size(); i++) cout << ans[ans.size() - 1 - i];

    return 0;
}