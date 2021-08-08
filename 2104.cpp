#include <iostream>

using namespace std;

int N;
long long int A[100000 + 1];

long long int min (long long int ll1, long long int ll2) {
    return ll1 < ll2 ? ll1 : ll2;
}

long long int max (long long int ll1, long long int ll2) {
    return ll1 > ll2 ? ll1 : ll2;
}

long long int maxScore (int start, int finish) {
    if (start == finish) return A[start] * A[start];
    
    int mid = (start + finish) / 2;
    long long int leftScore = maxScore(start, mid);
    long long int rightScore = maxScore(mid + 1, finish);
    
    int leftPos = mid, rightPos = mid;
    long long int minScore = A[mid], scoreSum = A[mid];
    long long int mergeScore = scoreSum * minScore;
    while (start < leftPos && rightPos < finish) {
        if (A[leftPos - 1] > A[rightPos + 1]) {
            leftPos--;
            scoreSum += A[leftPos];
            minScore = min(minScore, A[leftPos]);
        } else {
            rightPos++;
            scoreSum += A[rightPos];
            minScore = min(minScore, A[rightPos]);
        }
        mergeScore = max(mergeScore, scoreSum * minScore);
    }
    
    while (start < leftPos) {
        leftPos--;
        scoreSum += A[leftPos];
        minScore = min(minScore, A[leftPos]);
        mergeScore = max(mergeScore, scoreSum * minScore);
    }
    while (rightPos < finish) {
        rightPos++;
        scoreSum += A[rightPos];
        minScore = min(minScore, A[rightPos]);
        mergeScore = max(mergeScore, scoreSum * minScore);
    }
    
    return max(max(leftScore, rightScore), mergeScore);
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    
    cout << maxScore(1, N);
    
    return 0;
}