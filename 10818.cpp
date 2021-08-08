#include <iostream>
#include <algorithm>

using namespace std;

int N, num;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    int maxVal = -1e6 - 1, minVal = 1e6 + 1;
    for (int i = 0; i < N; i++) {
        cin >> num;
        maxVal = max(maxVal, num);
        minVal = min(minVal, num);
    }

    cout << minVal << " " << maxVal;

    return 0;
}