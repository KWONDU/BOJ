#include <iostream>

using namespace std;

int x;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> x;

    int i = 0;
    while (x > i * (i + 1) / 2) {i++;}
    int j = x - (i - 1) * i / 2;
    if (i % 2 == 0) cout << j << "/" << (i + 1 - j);
    else cout << (i + 1 - j) << "/" << j;
    
    return 0;
}