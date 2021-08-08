#include <iostream>
#include <memory.h>
#include <vector>

using namespace std;

int N, M;

void nAndM3 (vector<int> ans, int depth) {
    if (depth == M) {
        for (int i : ans) cout << i << " ";
        cout << "\n";
        return ;
    }

    for (int i = 0; i < N; i++) {
        ans[depth] = i + 1;
        nAndM3(ans, depth + 1);
        ans[depth] = 0;
    }
    return ;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    vector<int> ans;
    for (int i = 0; i < M; i++) ans.push_back(0);

    nAndM3(ans, 0);

    return 0;
}