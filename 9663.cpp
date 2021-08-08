#include <iostream>
#include <memory.h>

using namespace std;

int N, cnt;
bool col[15], dFromLeftToRight[2 * 15 - 1], dFromRightToLeft[2 * 15 - 1];

void nqueen (int depth) {
    if (depth == N) {
        cnt ++;
        return ;
    }

    int i = depth;
    for (int j = 0; j < N; j++) {
        if (!col[j] && !dFromLeftToRight[j - i + N - 1] && !dFromRightToLeft[i + j]) {
            col[j] = true;
            dFromLeftToRight[j - i + N - 1] = true;
            dFromRightToLeft[i + j] = true;
            nqueen(depth + 1);
            col[j] = false;
            dFromLeftToRight[j - i + N - 1] = false;
            dFromRightToLeft[i + j] = false;
        }
    }

    return ;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    memset(col, false, sizeof(col));
    memset(dFromLeftToRight, false, sizeof(dFromLeftToRight));
    memset(dFromRightToLeft, false, sizeof(dFromRightToLeft));
    cnt = 0;
    nqueen(0);

    cout << cnt;

    return 0;
}