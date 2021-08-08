#include <iostream>
#include <string>

using namespace std;

int T;
string temp;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> temp;

        int score = 0, cnt = 1;
        for (int i = 0; i < temp.length(); i++) {
            if (temp[i] == 'O') {
                score += cnt;
                cnt++;
            } else cnt = 1;
        }

        cout << score << "\n";
    }

    return 0;
}