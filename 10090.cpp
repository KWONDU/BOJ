#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[1000000];

long long int cal (int left, int right) {
    if (left >= right) return 0;
    
    int mid = (left + right) / 2;
    
    long long int cntLeft = cal(left, mid);
    long long int cntRight = cal(mid + 1, right);
    
    long long int cntMerge = 0;
    int leftArr[500000];
    for (int i = left; i <= mid; i++) leftArr[i - left] = a[i];
    int rightArr[500000];
    for (int i = mid + 1; i <= right; i++) rightArr[i - mid - 1] = a[i];
    
    sort(leftArr, leftArr + (mid - left + 1));
    sort(rightArr, rightArr + (right - mid));
    
    int j = 0;
    for (int i = 0; i < mid - left + 1; i++) {
        while (j < right - mid) {
            if (leftArr[i] > rightArr[j]) j++;
            else break;
        }
        cntMerge += j;
    }
    
    return cntLeft + cntRight + cntMerge;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    cout << cal(0, n - 1);
    
    return 0;
}