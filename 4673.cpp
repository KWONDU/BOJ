#include <iostream>

using namespace std;

bool num[10001];

int d (int n) {
    int selfNum = n;
    while (n > 0) {
        selfNum += n % 10;
        n /= 10;
    }
    return selfNum;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 1; i <= 10000; i++) {
        if (d(i) <= 10000) num[d(i)] = true;
    }

    for (int i = 1; i <= 10000; i++) {
        if (!num[i]) cout << i << "\n";
    }

    return 0;
}