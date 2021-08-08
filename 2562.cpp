#include <iostream>

using namespace std;

int num[9];

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 0; i < 9; i++) cin >> num[i];

    int maxVal = num[0], pos = 0;
    for (int i = 1; i < 9; i++) {
        if (maxVal < num[i]) {
            maxVal = num[i];
            pos = i;
        }
    }

    cout << maxVal << "\n" << (pos + 1);

    return 0;
}