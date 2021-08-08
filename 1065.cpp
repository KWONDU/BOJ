#include <iostream>

using namespace std;

int N;

bool func (int num) {
    bool chk = true;

    int diff = num / 10 % 10 - num % 10;
    while (num >= 10) {
        if (num % 10 + diff != num / 10 % 10) {
            chk = false;
            break;
        }
        num = num / 10;
    }
    return chk;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    int cnt = 0;
    for (int i = 1; i <= N; i++)
        if (func(i)) cnt++;
    cout << cnt;

    return 0;
}