#include <iostream>

using namespace std;

int pos[3][2];

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 0; i < 3; i++) cin >> pos[i][0] >> pos[i][1];

    int posX, posY;

    if (pos[0][0] == pos[1][0]) posX = pos[2][0];
    else if (pos[0][0] == pos[2][0]) posX = pos[1][0];
    else posX = pos[0][0];

    if (pos[0][1] == pos[1][1]) posY = pos[2][1];
    else if (pos[0][1] == pos[2][1]) posY = pos[1][1];
    else posY = pos[0][1];

    cout << posX << " " << posY;

    return 0;
}