#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int N, x, y;
vector<pair<int, int>> v;

bool comp (pair<int, int> p1, pair<int, int> p2) {
    if (p1.first == p2.first) return p1.second < p2.second;
    else return p1.first < p2.first;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    while (N--) {
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }

    sort(v.begin(), v.end(), comp);

    for (auto pos : v) cout << pos.first << " " << pos.second << "\n";

    return 0;
}