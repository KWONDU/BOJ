#include <iostream>
#include <string>
#include <map>

using namespace std;

int T, n;
string s1, s2;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;

    while (T--) {
        map<string, int> m;
        cin >> n;

        while (n--) {
            cin >> s1 >> s2;

            if (m.find(s2) == m.end()) {
                m.insert(make_pair(s2, 1));
            } else m[s2]++;
        }

        int ans = 1;
        for (auto i : m) {
            ans *= (i.second + 1);
        }
        ans--;
        cout << ans << "\n";
    }

    return 0;
}