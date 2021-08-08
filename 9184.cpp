#include <iostream>

using namespace std;

int a, b, c, w[21][21][21];

int funcw (int x, int y, int z) {
    if (x <= 0 || y <= 0 || z <= 0) return 1;
    else if (x > 20 || y > 20 || z > 20) return funcw(20, 20, 20);
    else if (x < y && y < z) return w[x][y][z - 1] + w[x][y - 1][z - 1] - w[x][y - 1][z];
    else return w[x - 1][y][z] + w[x - 1][y - 1][z] + w[x - 1][y][z - 1] - w[x - 1][y - 1][z - 1];
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            for (int k = 0; k < 21; k++) w[i][j][k] = funcw(i, j, k);
        }
    }

    while (true) {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) break;

        cout << "w(" << a << ", " << b << ", " << c << ") = " << funcw(a, b, c) << "\n";
    }

    return 0;
}