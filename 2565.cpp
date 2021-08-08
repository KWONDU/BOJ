#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> line;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int u, v;
        cin >> u >> v;
        line.push_back(make_pair(u, v));
    }

    sort(line.begin(), line.end());

    int cnt[100], pos = 0;
    for (int i = 0; i < N; i++) {
        if (pos == 0 || cnt[pos - 1] < line[i].second) cnt[pos++] = line[i].second;
        else {
            int l = 0, r = pos, m;
            while (l < r) {
                m = (l + r) / 2;
                if (cnt[m] >= line[i].second) r = m;
                else l = m + 1;
            }
            cnt[l] = line[i].second;
        }
    }

    cout << (N - pos);

    return 0;
}