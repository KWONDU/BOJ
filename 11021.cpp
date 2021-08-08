#include <iostream>

using namespace std;

int T, A, B;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;

    for (int x = 1; x <= T; x++) {
        cin >> A >> B;
        cout << "Case #" << x << ": " << (A + B) << "\n";
    }    
}