#include <iostream>
#include <memory.h>
#include <vector>

using namespace std;

int N, M;

void nAndM1 (vector<bool> chk, vector<int> ans, int depth) {
    if (depth == M) {
        for (int i : ans) cout << i << " ";
        cout << "\n";
        return ;
    }

    for (int i = 0; i < N; i++) {
        if (!chk[i]) {
            chk[i] = true;
            ans[depth] = i + 1;
            nAndM1(chk, ans, depth + 1);
            chk[i] = false;
            ans[depth] = 0;
        }
    }
    return ;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    vector<bool> chk;
    for (int i = 0; i < N; i++) chk.push_back(false);
    vector<int> ans;
    for (int i = 0; i < M; i++) ans.push_back(0);

    nAndM1(chk, ans, 0);

    return 0;
}