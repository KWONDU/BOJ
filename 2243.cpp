#include <iostream>

using namespace std;

const int MAX = 1e6;

int n, A, B, C;

int seg[1<<21];

void update (int node, int left, int right, int updateIdx, int val) {
    if (updateIdx < left || right < updateIdx) return ;
    else if (updateIdx == left && right == updateIdx) {
        seg[node] += val;
        return ;
    }
    
    int mid = (left + right) / 2;
    update(node * 2, left, mid, updateIdx, val);
    update(node * 2 + 1, mid + 1, right, updateIdx, val);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
    return ;
}

int query (int node, int left, int right, int sum) {
    if (left == right) return left;
    
    int mid = (left + right) / 2;
    if (sum <= seg[node * 2]) return query(node * 2, left, mid, sum);
    else return query(node * 2 + 1, mid + 1, right, sum - seg[node * 2]);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    while (n--) {
        cin >> A;
        int num;
        switch(A) {
            case 1 :
                cin >> B;
                num = query(1, 1, MAX, B);
                cout << num << "\n";
                update(1, 1, MAX, num, -1);
                break;
            case 2 :
                cin >> B >> C;
                update(1, 1, MAX, B, C);
                break;
        }
    }
    
    return 0;
}