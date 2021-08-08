#include <iostream>

using namespace std;

int num, a[50];

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> num;
    for (int i = 0; i < num; i++) cin >> a[i];

    int minVal = 1000001, maxVal = 1;
    for (int i = 0; i < num; i++) {
        if (a[i] < minVal) minVal = a[i];
        if (a[i] > maxVal) maxVal = a[i];
    }
    cout << minVal * maxVal;

    return 0;
}