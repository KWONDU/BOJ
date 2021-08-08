#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int min (int n1, int n2) {
    if (n1 < n2)
        return n1;
    else
        return n2;
}

int min (int n1, int n2, int n3) {
    return min(min(n1, n2), n3);
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    
    int* arr = new int[1000000 + 1];
    for (int i = 1; i <= n; i++) {
        if (i == 1)
            arr[i] = 0;
        else if (i == 2 || i == 3)
            arr[i] = 1;
        else {
            if (i % 3 == 0 && i % 2 == 0)
                arr[i] = min(arr[i / 3], arr[i / 2], arr[i - 1]) + 1;
            else if (i % 3 == 0)
                arr[i] = min(arr[i / 3], arr[i - 1]) + 1;
            else if (i % 2 == 0)
                arr[i] = min(arr[i / 2], arr[i - 1]) + 1;
            else
                arr[i] = arr[i - 1] + 1;
        }
    }
    
    cout << arr[n];
}