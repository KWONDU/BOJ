#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool binarysearch (int* a, int len, int temp) {
    int left = 0;
    int right = len - 1;
    int mid;
    bool chk = false;
    while (left <= right) {
        mid = (left + right) / 2;
        
        if (a[mid] < temp)
            left = mid + 1;
        else if (a[mid] > temp)
            right = mid - 1;
        else {
            chk = true;
            break;
        }
    }
    
    return chk;
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int m;
    cin >> m;
    
    int temp;
    for (int i = 0; i < m; i++) {
        cin >> temp;
        cout << binarysearch(a, n, temp) << "\n";
    }
}