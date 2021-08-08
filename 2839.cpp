#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    
    int min = n;
    for (int i = n / 5; i >= 0; i--) {
        if ((n - i * 5) % 3 == 0) {
            int temp = i + (n - i * 5) / 3;
            if (temp < min)
                min = temp;
        }
    }
    
    if (min == n)
        cout << "-1";
    else
        cout << min;
}