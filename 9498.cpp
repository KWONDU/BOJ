#include <iostream>

using namespace std;

int n;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    
    if (n < 60) cout << "F";
    else if (n < 70) cout << "D";
    else if (n < 80) cout << "C";
    else if (n < 90) cout << "B";
    else cout << "A";
}