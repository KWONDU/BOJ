#include <iostream>

using namespace std;

int N;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    
    int cnt = 0, i = 1;
    while (i < N) {
        int sum = i, temp = i;
        while (temp != 0) {
            sum += temp % 10;
            temp /= 10;
        }

        if (sum == N) {
            cnt = i;
            break;
        }

        i++;
    }

    cout << cnt;

    return 0;
}