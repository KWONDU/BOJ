#include <iostream>

using namespace std;

int N;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) cout << " ";
        for (int j = 0; j < (N * 2 - i * 2 - 1); j++) cout << "*";
        cout << "\n";
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < (N - 2 - i); j++) cout << " ";
        for (int j = 0; j < (i * 2 + 3); j++) cout << "*";
        cout << "\n";
    }

    return 0;
}