#include <iostream>

using namespace std;

int N;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < (N + 1) / 2; j++) cout << "* ";
        cout << "\n";
        for (int j = 0; j < N / 2; j++) cout << " *";
        cout << "\n";
    }

    return 0;
}