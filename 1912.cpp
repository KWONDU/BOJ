#include <iostream>

using namespace std;

int n;
int arr[100000];

int MIN = -1000 * 100000 - 1;

int max (int n1, int n2) {
    return n1 > n2 ? n1 : n2;
}

int max (int n1, int n2, int n3) {
    return max(max(n1, n2), n3);
}

int cal (int left, int right) {
    if (left > right) return 0;
    else if (left == right) return arr[left];
    
    int mid = (left + right) / 2;
    
    int leftSum = MIN, rightSum = MIN;
    int tempSum = 0;
    for (int i = mid; i >= left; i--) {
        tempSum += arr[i];
        leftSum = max(leftSum, tempSum);
    }
    tempSum = 0;
    for (int i = mid + 1; i <= right; i++) {
        tempSum += arr[i];
        rightSum = max(rightSum, tempSum);
    }
    
    return max(cal(left, mid), cal(mid + 1, right), leftSum + rightSum);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    cout << cal(0, n - 1);
    
    return 0;
}