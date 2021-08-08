#include <iostream>

using namespace std;

int N, K;
int arr[3][5000000];

int minPos(int pos1, int pos2, int chk) {
    return arr[chk][pos1] < arr[chk][pos2] ? pos1 : pos2;
}

int maxPos(int pos1, int pos2, int chk) {
    return arr[chk][pos1] > arr[chk][pos2] ? pos1 : pos2;
}

int selectPivot(int low, int high, int chk, int cnt) {
    int mid1 = (low + high) / 3, mid2 = (low + high) * 2 / 3;
    
    int minPivotPos = minPos(minPos(minPos(low, mid1, chk), mid2, chk), high, chk);
    int maxPivotPos = maxPos(maxPos(maxPos(low, mid1, chk), mid2, chk), high, chk);
    
    if (cnt <= (high - low + 1) / 6) return minPivotPos;
    else if (cnt >= (high - low + 1) * 5 / 6) return maxPivotPos;
    else {
        int remain[2]; int tempPos = 0;
        if (low != minPivotPos && low != maxPivotPos) remain[tempPos++] = low;
        if (mid1 != minPivotPos && mid1 != maxPivotPos) remain[tempPos++] = mid1;
        if (mid2 != minPivotPos && mid2 != maxPivotPos) remain[tempPos++] = mid2;
        if (high != minPivotPos && high != maxPivotPos) remain[tempPos++] = high;
        
        if (cnt <= (high - low + 1) * 3 / 6) return minPos(remain[0], remain[1], chk);
        else return maxPos(remain[0], remain[1], chk);
    }
}

int Kth (int chk, int sz, int cnt) {
    int smaller = (chk + 1) % 3, same = chk, larger = (chk + 2) % 3;
    
    int pivotPos = selectPivot(0, sz - 1, same, cnt);
    int pivot = arr[same][pivotPos];
    int sI = 0, lI = 0;
    for (int i = 0; i < sz; i++) {
        if (i == pivotPos) continue;
        
        if (arr[same][i] < pivot) arr[smaller][sI++] = arr[same][i];
        else if (arr[same][i] > pivot) arr[larger][lI++] = arr[same][i];
    }
    
    if (cnt <= sI) return Kth(smaller, sI, cnt);
    else if (cnt <= (sz - lI)) return pivot;
    else return Kth(larger, lI, cnt - (sz - lI));
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> arr[0][i];
    
    cout << Kth(0, N, K);
    
    return 0;
}