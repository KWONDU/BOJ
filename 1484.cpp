#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int g;
    cin >> g;
    
    int* arr = new int[(g + 1) / 2 + 1];
    for (int i = 0; i <= (g + 1) / 2; i++) arr[i] = i * i;
    
    bool chk = false;
    int temp, cnt = 0;
    int pos1 = 0, pos2 = 0;
    while (pos2 <= (g + 1) / 2) {
        temp = arr[pos2] - arr[pos1];
        if (temp < g)
            pos2++;
        else if (temp > g)
            pos1++;
        else {
            if (pos1 != 0) {
                cout << pos2 << "\n";
                chk = true;
            }
            pos2++;
        }
    }
    if (!chk) cout << "-1";
}