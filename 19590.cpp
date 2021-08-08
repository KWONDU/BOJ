#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    long long int totalsum = 0;
    int x[100000];
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        totalsum += x[i];
    }
    
    sort(x, x + n);
    if (totalsum - x[n - 1] < x[n - 1])
        cout << (x[n - 1] - (totalsum - x[n - 1]));
    else {
        if (totalsum % 2 == 0)
            cout << "0";
        else
            cout << "1";
    }
}