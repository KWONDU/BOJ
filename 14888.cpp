#include <iostream>
#include <memory.h>

using namespace std;

char c[4] = {'+', '-', '*', '/'};

int N, A[11], cnt[4];
bool chk[10];
char op[10];

int maxVal = -1e9 - 1, minVal = 1e9 + 1;

void cal (int depth, int ans) {
    if (depth == N) {
        maxVal = max(maxVal, ans);
        minVal = min(minVal, ans);
        return ;
    }

    for (int i = 0; i < N - 1; i++) {
        if (!chk[i]) {
            chk[i] = true;
            if (op[i] == '+') cal(depth + 1, ans + A[depth]);
            else if (op[i] == '-') cal(depth + 1, ans - A[depth]);
            else if (op[i] == '*') cal(depth + 1, ans * A[depth]);
            else cal(depth + 1, ans / A[depth]);
            chk[i] = false;
        }
    }

    return ;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < 4; i++) cin >> cnt[i];

    memset(chk, false, sizeof(chk));

    int pos = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            op[pos++] = c[i];
        }
    }

    cal(1, A[0]);

    cout << maxVal << "\n" << minVal;

    return 0;
}