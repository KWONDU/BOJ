#include <iostream>
#include <string>

using namespace std;

int T, R;
string S;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;

    while (T--) {
        cin >> R >> S;

        for (int i = 0; i < S.length(); i++) {
            for (int j = 0; j < R; j++) cout << S[i];
        }
        cout << "\n";
    }

    return 0;
}