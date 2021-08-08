#include <iostream>
#include <string>

using namespace std;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string S;
    cin >> S;

    for (int i = 0; i < 26; i++) {
        char x = (char)(i + 97);
        if (S.find(x) == string::npos) cout << "-1 ";
        else cout << S.find(x) << " ";
    }

    return 0;
}