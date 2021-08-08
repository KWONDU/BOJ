#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

void mergesort (int* arr, int left, int mid, int right) {
    int first = left;
    int second = mid + 1;
    int* temparr = new int[right - left + 1];
    int pos = 0;
    
    while (first <= mid && second <= right) {
        if (arr[first] < arr[second]) {
            temparr[pos] = arr[first];
            first++;
            pos++;
        }
        else {
            temparr[pos] = arr[second];
            second++;
            pos++;
        }
    }
    
    if (first <= mid)
        for (int i = first; i <= mid; i++) {
            temparr[pos] = arr[i];
            pos++;
        }
    else
        for (int i = second; i <= right; i++) {
            temparr[pos] = arr[i];
            pos++;
        }
    
    for (int i = left; i <= right; i++)
        arr[i] = temparr[i - left];
    return;
}

void merge (int* arr, int left, int right) {
    if (left == right)
        return;
    
    int mid = (left + right) / 2;
    merge(arr, left, mid);
    merge(arr, mid + 1, right);
    mergesort(arr, left, mid, right);
    return;
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    merge(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << "\n";
}