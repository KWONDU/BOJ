#include <iostream>
#include <memory.h>

using namespace std;

int n, q, a, type, i, j, l, u;

int segOdd[1<<19], segEven[1<<19];

void update (int node, int left, int right, int updateIdx, int val) {
    if (updateIdx < left || right < updateIdx) return ;
    else if (left == updateIdx && updateIdx == right) {
        if (updateIdx % 2 == 0) segEven[node] = val;
        else segOdd[node] = val;
        return ;
    }
    
    int mid = (left + right) / 2;
    update(node * 2, left, mid, updateIdx, val);
    update(node * 2 + 1, mid + 1, right, updateIdx, val);
    
    if (updateIdx % 2 == 0) segEven[node] = segEven[node * 2] ^ segEven[node * 2 + 1];
    else segOdd[node] = segOdd[node * 2] ^ segOdd[node * 2 + 1];
    
    return ;
}

int query (int node, int left, int right, int queryLeft, int queryRight) {
    if (queryRight < left || right < queryLeft) return 0;
    else if (queryLeft <= left && right <= queryRight) {
        if (queryLeft % 2 == 0) return segEven[node];
        else return segOdd[node];
    }
    
    int mid = (left + right) / 2;
    return query(node * 2, left, mid, queryLeft, queryRight) ^ query(node * 2 + 1, mid + 1, right, queryLeft, queryRight);
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    memset(segOdd, 0, sizeof(segOdd));
    memset(segEven, 0, sizeof(segEven));
    
    // 1, 2, ---, n 에 대해 k는 k * (n - k + 1) 번 계산된다
    // (1+2+---+k, ---, (k-1)+k, k) * (k, k+(k+1), ---, k+---+n)
    // n이 짝수인 경우 k * (n - k + 1)은 항상 짝수 => XOR 연산 결과 = 0
    // n이 홀수인 경우 k가 홀수일 때 => 값 존재, 짝수일 때 => 0
    // k의 홀짝성은 range의 시작 값에 따라 달라짐
    
    cin >> n >> q;
    for (int idx = 1; idx <= n; idx++) {
        cin >> a;
        update(1, 1, n, idx, a);
    }
    while (q--) {
        cin >> type;
        switch (type) {
            case 1 :
                cin >> i >> j;
                update(1, 1, n, i, j);
                break;
            case 2 :
                cin >> l >> u;
                if ((u - l + 1) % 2 == 0) cout << "0\n";
                else cout << query(1, 1, n, l, u) << "\n";
                break;
        }
    }
    
    return 0;
}