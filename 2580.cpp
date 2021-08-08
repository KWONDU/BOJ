#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int sudoku[9][9];
vector<pair<int, int>> zero;
bool row[9][9];
bool column[9][9];
bool square[9][9];
bool chk;

void fill();
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    fill_n(row[0], 81, false);
    fill_n(column[0], 81, false);
    fill_n(square[0], 81, false);
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++) {
            cin >> sudoku[i][j];
            if (sudoku[i][j] == 0) {
                zero.push_back(make_pair(i, j));
                continue;
            }
            
            row[i][sudoku[i][j] - 1] = true;
            column[j][sudoku[i][j] - 1] = true;
            square[i / 3 * 3 + j / 3][sudoku[i][j] - 1] = true;
        }
    
    chk = false;
    fill();
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            cout << sudoku[i][j] << " ";
        cout << "\n";
    }
}

void fill () {
    if (zero.empty()) {
        chk = true;
        return;
    }
    
    int x = zero.back().first;
    int y = zero.back().second;
    for (int k = 0; k < 9; k++)
        if (!row[x][k] && !column[y][k] && !square[x / 3 * 3 + y / 3][k]) {
            sudoku[x][y] = k + 1;
            zero.pop_back();
            row[x][k] = true; column[y][k] = true; square[x / 3 * 3 + y / 3][k] = true;
            fill();
            
            if (chk)
                return;
            
            sudoku[x][y] = 0;
            zero.push_back(make_pair(x, y));
            row[x][k] = false; column[y][k] = false; square[x / 3 * 3 + y / 3][k] = false;
        }
    
    return;
}