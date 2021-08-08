#include <iostream>
#include <string>

using namespace std;

string ex;
int temp = 0, ans = 0;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    getline(cin, ex);

    bool flag = false;
    for (int i = 0; i <= ex.length(); i++) {
        if (i == ex.length() || ex[i] == '+' || ex[i] == '-') {
            if (flag == false) {
                ans += temp;
                temp = 0;
            } else {
                ans -= temp;
                temp = 0;
            }

            if (ex[i] == '-') flag = true;
        } else {
            temp = temp * 10 + (ex[i] - '0');
        }
    }
    cout << ans;
    
    return 0;
}