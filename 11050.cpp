#include <iostream>

using namespace std;

int N, K;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;

    int num1 = 1;
    for (int i = N; i >= N - K + 1; i--) num1 *= i;
    
    int num2 = 1;
    for (int i = 1; i <= K; i++) num2 *= i;

    cout << (num1 / num2);

    return 0;
}