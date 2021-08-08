#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int N, num[500000];

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> num[i];
    sort(num, num + N);

    int sum = 0;
    for (int i = 0; i < N; i++) sum += num[i];
    cout << round((double)sum / N) << "\n";

    cout << num[(N - 1) / 2] << "\n";

    int most = 0, start = 0, finish = 0;
    while (start < N && finish < N) {
        if (num[start] == num[finish]) finish++;
        else {
            if (finish - start > most) most = finish - start;
            start = finish;
        }
    }
    if (finish - start > most) most = finish - start;
    start = 0, finish = 0;
    vector<int> v;
    while (start < N && finish < N) {
        if (num[start] == num[finish]) finish++;
        else {
            if (finish - start == most) v.push_back(num[start]);
            start = finish;
        }
    }
    if (finish - start == most) v.push_back(num[start]);
    if (v.size() == 1) cout << v[0] << "\n";
    else cout << v[1] << "\n";

    cout << (num[N - 1] - num[0]);

    return 0;
}