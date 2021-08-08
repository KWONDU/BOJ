#include <iostream>
#include <string>

using namespace std;

string stc;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    getline(cin, stc);
    int cnt = 0;

    for (int i = 0; i < stc.length(); i++)
        if (stc[i] == ' ')
            cnt++;
    if (stc[0] == ' ' && stc[stc.length() - 1] == ' ') cout << (cnt - 1);
    else if (stc[0] == ' ' || stc[stc.length() - 1] == ' ') cout << cnt;
    else cout << (cnt + 1);

    return 0;
}