#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int N, cnt = 0;
vector<pair<int, int>> v;

void hanoi (int len, int start, int by, int to) {
    if (len == 1) {
        v.push_back(make_pair(start, to));
        cnt++;
    } else {
        hanoi(len - 1, start, to, by);
        v.push_back(make_pair(start, to));
        cnt++;
        hanoi(len - 1, by, start, to);
    }

    return ;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    hanoi(N, 1, 2, 3);

    cout << cnt << "\n";
    for (auto x : v) cout << x.first << " " << x.second << "\n";

    return 0;
}