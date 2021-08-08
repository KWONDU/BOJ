#include <iostream>
#include <memory.h>

using namespace std;

const int MAX = 200000;

int K, a[MAX + 1];

int maxSeg[1<<19], kthSeg[1<<19];

int max (int n1, int n2) {
    return n1 > n2 ? n1 : n2;
}

void updateMaxSeg (int node, int left, int right, int updateIdx, int val) {
    if (updateIdx < left || right < updateIdx) return ;
    else if (left == updateIdx && updateIdx == right) {
        maxSeg[node] = val;
        return ;
    }
    
    int mid = (left + right) / 2;
    updateMaxSeg(node * 2, left, mid, updateIdx, val);
    updateMaxSeg(node * 2 + 1, mid + 1, right, updateIdx, val);
    maxSeg[node] = max(maxSeg[node * 2], maxSeg[node * 2 + 1]);
    
    return ;
}

int findMax (int node, int left, int right, int queryLeft, int queryRight) {
    if (queryRight < left || right < queryLeft) return 0;
    else if (queryLeft <= left && right <= queryRight) return maxSeg[node];
    
    int mid = (left + right) / 2;
    return max(findMax(node * 2, left, mid, queryLeft, queryRight), findMax(node * 2 + 1, mid + 1, right, queryLeft, queryRight));
}

void updateKthSeg (int node, int left, int right, int updateIdx) {
    if (updateIdx < left || right < updateIdx) return ;
    else if (left == updateIdx && updateIdx == right) {
        kthSeg[node]++;
        return ;
    }
    
    int mid = (left + right) / 2;
    updateKthSeg(node * 2, left, mid, updateIdx);
    updateKthSeg(node * 2 + 1, mid + 1, right, updateIdx);
    kthSeg[node] = kthSeg[node * 2] + kthSeg[node * 2 + 1];
    
    return ;
}

int findKth (int node, int left, int right, int kth) {
    if (kthSeg[node] < kth) return MAX + 1;
    else if (left == right) return left;
    
    int mid = (left + right) / 2;
    if (kthSeg[node * 2] >= kth) return findKth(node * 2, left, mid, kth);
    else return findKth(node * 2 + 1, mid + 1, right, kth - kthSeg[node * 2]);
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    memset(maxSeg, 0, sizeof(maxSeg));
    memset(kthSeg, 0, sizeof(kthSeg));
    
    cin >> K;
    for (int i = 1; i <= K; i++) {
        cin >> a[i];
        updateMaxSeg(1, 1, K, i, a[i]);
    }
    
    int N = 0, M = 0;
    for (int idx = K; idx >= 1; idx--) {
        if (a[idx] * 2 <= (K - idx)) {
            int tempN = findMax(1, 1, K, 1, idx - 1), compN = findKth(1, 1, MAX, a[idx] * 2);
            if (tempN >= compN) {
                if (N < tempN) {
                    N = tempN;
                    M = a[idx];
                } else if (N == tempN) M = max(M, a[idx]);
            }
        }
        updateKthSeg(1, 1, MAX, a[idx]);
    }
    
    if (N == 0 && M == 0) cout << "-1";
    else cout << N << " " << M;
    
    return 0;
}