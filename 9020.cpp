#include <iostream>

using namespace std;

int T, n;

bool pChk (int num) {
    int div = 2;
    while (div * div <= num) {
        if (num % div == 0) return false;
        div++;
    }

    if (num == 1) return false;
    else return true;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    
    while (T--) {
        cin >> n;

        int x = n / 2;
        while (!pChk(x) || !pChk(n - x)) { x--; }

        cout << x << " " << (n - x) << "\n";
    }

    return 0;
}