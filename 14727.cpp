#include <iostream>

using namespace std;

int N;
long long int H[100000 + 1];

int min (int n1, int n2) {
    return n1 < n2 ? n1 : n2;
}

long long int max (long long int ll1, long long int ll2) {
    return ll1 > ll2 ? ll1 : ll2;
}

long long int maxArea (int start, int finish) {
    if (start == finish) return H[start];
    
    int leftPos = (start + finish) / 2, rightPos = (start + finish) / 2;
    long long int mergeHeight = H[(start + finish) / 2];
    long long int mergeArea = mergeHeight;
    while (leftPos > start && rightPos < finish) {
        if (H[leftPos - 1] > H[rightPos + 1]) {
            leftPos--;
            mergeHeight = min(mergeHeight, H[leftPos]);
            mergeArea = max(mergeArea, mergeHeight * (rightPos - leftPos + 1));
        } else {
            rightPos++;
            mergeHeight = min(mergeHeight, H[rightPos]);
            mergeArea = max(mergeArea, mergeHeight * (rightPos - leftPos + 1));
        }
    }
    
    while (leftPos > start) {
        leftPos--;
        mergeHeight = min(mergeHeight, H[leftPos]);
        mergeArea = max(mergeArea, mergeHeight * (rightPos - leftPos + 1));
    }
    while (rightPos < finish) {
        rightPos++;
        mergeHeight = min(mergeHeight, H[rightPos]);
        mergeArea = max(mergeArea, mergeHeight * (rightPos - leftPos + 1));
    }
    
    long long int leftArea = maxArea(start, (start + finish) / 2);
    long long int rightArea = maxArea((start + finish) / 2 + 1, finish);
    
    return max(max(leftArea, rightArea), mergeArea);
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> H[i];
    
    cout << maxArea(1, N);
    
    return 0;
}