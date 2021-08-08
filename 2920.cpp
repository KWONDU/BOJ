#include <iostream>

using namespace std;

int sound[8];

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 0; i < 8; i++) cin >> sound[i];

    bool aChk = true;
    for (int i = 0; i < 7; i++) {
        if (sound[i + 1] < sound[i]) {
            aChk = false;
            break;
        }
    }

    bool dChk = true;
    for (int i = 0; i < 7; i++) {
        if (sound[i + 1] > sound[i]) {
            dChk = false;
            break;
        }
    }

    if (aChk) cout << "ascending";
    else if (dChk) cout << "descending";
    else cout << "mixed";

    return 0;
}