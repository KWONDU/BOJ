#include <iostream>

using namespace std;

int N;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    
    int ans = 1;
    for (int i = 1; i <= N; i++) ans *= i;
    cout << ans;

    return 0;
}