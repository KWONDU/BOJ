#include <iostream>

using namespace std;

int N;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    int len = 0, tempN = N;
    while (true) {
        N = (N % 10) * 10 + ((N / 10) + (N % 10)) % 10;
        len++;
        if (N == tempN) break;
    }
    cout << len;
    
    return 0;
}