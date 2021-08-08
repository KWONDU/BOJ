#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<pair<int, string>, int>> v;

bool comp (pair<pair<int, string>, int> p1, pair<pair<int, string>, int> p2) {
    if (p1.first.first == p2.first.first) {
        return p1.second < p2.second;
    } else return p1.first.first < p2.first.first;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    int tempInt;
    string tempStr;
    for (int i = 0; i < N; i++) {
        cin >> tempInt >> tempStr;
        v.push_back(make_pair(make_pair(tempInt, tempStr), i));
    }

    sort(v.begin(), v.end(), comp);

    for (auto x : v) cout << x.first.first << " " << x.first.second << "\n";

    return 0;
}