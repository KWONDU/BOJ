#include <iostream>
#include <string>

using namespace std;

int N;
string img[64];

void quadtree (int xPos, int yPos, int len) {
    bool mergeChk = true;
    for (int i = xPos; i < xPos + len; i++) {
        for (int j = yPos; j < yPos + len; j++) {
            if (img[xPos][yPos] != img[i][j]) {
                mergeChk = false;
                break;
            }
        }

        if (!mergeChk) break;
    }

    if (mergeChk) {
        cout << img[xPos][yPos];
        return ;
    } else {
        cout << "(";
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                quadtree(xPos + len / 2 * i, yPos + len / 2 * j, len / 2);
            }
        }
        cout << ")";
        return ;
    }
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> img[i];

    quadtree(0, 0, N);

    return 0;
}