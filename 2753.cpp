#include <iostream>

using namespace std;

int n;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    
    if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0) cout << "1";
    else cout << "0";

    return 0;
}