#include <iostream>

using namespace std;

int N, K;
int person[4242];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> K;
    
    int lowPerson = 1, highPerson = N;
    for (int i = 0; i < N; i++) {
        if (K >= (N - i - 1)) {
            K -= (N - i - 1);
            person[i] = highPerson--;
        } else person[i] = lowPerson++;
    }
    
    for (int i = 0; i < N; i++) cout << person[i] << " ";
    
    return 0;
}