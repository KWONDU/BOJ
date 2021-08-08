#include <iostream>

using namespace std;

int waterX, waterY;
int tile[128 + 1][128 + 1];

int cnt = 0;

int savePower2[8];
int power2 (int exponent) {
    if (savePower2[exponent] != -1) return savePower2[exponent];
    
    if (exponent == 0) return savePower2[0] = 1;
    else return savePower2[exponent] = 2 * power2(exponent - 1);
}

void fill(int x, int y, int k, int chk);
void where (int x, int y, int k);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    int K;
    cin >> K;
    cin >> waterX >> waterY;
    
    for (int i = 0; i <= 7; i++) savePower2[i] = -1;
    
    where(1, 1, K);
    
    tile[waterX][waterY] = -1;
    for (int i = power2(K); i >= 1; i--) {
        for (int j = 1; j <= power2(K); j++) cout << tile[j][i] << " ";
        cout << endl;
    }
    
    return 0;
}

void where (int x, int y, int k) {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            if (x + i * power2(k - 1) <= waterX && waterX < x + (i + 1) * power2(k - 1) && y + j * power2(k - 1) <= waterY && waterY < y + (j + 1) * power2(k - 1))
                fill(x, y, k, i * 2 + j);
    
    return;
}

void fill (int x, int y, int k, int chk) {
    int chkX = chk / 2, chkY = chk % 2;
    
    if (k == 1) {
        cnt++;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                if (i != chkX || j != chkY) tile[x + i][y + j] = cnt;
        return;
    }
    
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
            if (i == chkX && j == chkY) {
                fill(x + power2(k - 2), y + power2(k - 2), k - 1, chk);
                where(x + chkX * power2(k - 1), y + chkY * power2(k - 1), k - 1);
            } else fill(x + i * power2(k - 1), y + j * power2(k - 1), k - 1, 3 - (i * 2 + j));
        }
    
    return;
}