#include <iostream>
#include <string>

using namespace std;

const int r = 31;
const int M = 1234567891;

int N;
string s;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> s;

    long long int hash = 0, ri = 1;
    for (int  i = 0; i < N; i++) {
        hash = (hash + (s[i] - 'a' + 1) * ri) % M;
        ri = ri * r % M;
    }

    cout << hash;

    return 0;
}