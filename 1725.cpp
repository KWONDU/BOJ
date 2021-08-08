#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int* rod;

int min (int n1, int n2) {
    if (n1 < n2)
        return n1;
    else
        return n2;
}

int max (int n1, int n2) {
    if (n1 > n2)
        return n1;
    else
        return n2;
}

int max (int n1, int n2, int n3) {
    return max(max(n1, n2), n3);
}

int mergearea (int left, int mid, int right);
int merge (int left, int right);

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    rod = new int[n];
    for (int i = 0; i < n; i++)
        cin >> rod[i];
    
    cout << merge(0, n - 1);
}

int mergearea (int left, int mid, int right) {
    int first = mid;
    int second = mid + 1;
    
    int maxarea = 0;
    int minheight = 1e9 + 1;
    int width = 2;
    if (rod[first] < rod[second]) {
        maxarea = rod[first] * width;
        minheight = rod[first];
    }
    else {
        maxarea = rod[second] * width;
        minheight = rod[second];
    }
    first--; second++;
    while (first >= left && second <= right) {
        width++;
        if (rod[first] > rod[second]) {
            minheight = min(rod[first], minheight);
            maxarea = max(maxarea, minheight * width);
            first--;
        }
        else {
            minheight = min(rod[second], minheight);
            maxarea = max(maxarea, minheight * width);
            second++;
        }
    }
    
    if (first < left)
        for (int i = second; i <= right; i++) {
            width++;
            minheight = min(rod[i], minheight);
            maxarea = max(maxarea, minheight * width);
        }
    else
        for (int i = first; i >= left; i--) {
            width++;
            minheight = min(rod[i], minheight);
            maxarea = max(maxarea, minheight * width);
        }
    
    return maxarea;
}

int merge (int left, int right) {
    if (left == right)
        return rod[left];
    
    int mid = (left + right) / 2;
    
    int temp1 = merge(left, mid);
    int temp2 = merge(mid + 1, right);
    int temp3 = mergearea(left, mid, right);
    return max(temp1, temp2, temp3);
}