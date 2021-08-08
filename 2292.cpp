#include <iostream>

using namespace std;

int N;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    
    int chk = 1, i = 0;
    while (N > chk) {
        chk += (i * 6);
        i++;
    }

    if (N == 1) cout << "1";
    else cout << i;

    return 0;
}