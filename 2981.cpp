#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, num[100];
vector<int> diff;

int gcd (int n1, int n2) {
    while (n1 > 0 && n2 > 0) {
        if (n1 > n2) n1 %= n2;
        else n2 %= n1;
    }

    if (n1 == 0) return n2;
    else return n1;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> num[i];

    for (int i = 1; i < N; i++) diff.push_back(abs(num[i] - num[i - 1]));

    int M = gcd(diff[0], diff[1]);
    for (int i = 2; i < N; i++) M = gcd(M, diff[i]);

    vector<int> ans;
    for (int i = 2; i * i <= M; i++) {
        if (M % i == 0) {
            if (i * i == M) ans.push_back(i);
            else {
                ans.push_back(i);
                ans.push_back(M / i);
            }
        }
    }

    sort(ans.begin(), ans.end());

    for (int a : ans) cout << a << " ";
    cout << M;

    return 0;
}