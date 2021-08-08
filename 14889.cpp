#include <iostream>
#include <memory.h>
#include <vector>

using namespace std;

int N, S[20][20], diff;
bool team[20];

void stats (int depth, int prev) {
    if (depth == N / 2) {
        vector<int> start, link;
        for (int i = 0; i < N; i++) {
            if (team[i]) {
                start.push_back(i);
            } else link.push_back(i);
        }

        int startSum = 0, linkSum = 0;
        for (int i = 0; i < N / 2; i++) {
            for (int j = 0; j < N / 2; j++) {
                startSum += S[start[i]][start[j]];
                linkSum += S[link[i]][link[j]];
            }
        }

        int temp;
        if (startSum > linkSum) temp = startSum - linkSum;
        else temp = linkSum - startSum;

        if (diff == -1) diff = temp;
        else if (diff > temp) diff = temp;
        return ;
    }

    for (int i = 0; i < N; i++) {
        if (!team[i] && prev == 0 || prev < i) {
            team[i] = true;
            stats(depth + 1, i);
            team[i] = false;
        }
    }
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin >> S[i][j];
    }

    memset(team, false, sizeof(team));
    diff = -1;

    stats(0, 0);
    cout << diff;

    return 0;
}