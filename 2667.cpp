#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

const int INF = 25 * 25 + 1;

int N;
int map[25][25];

int cnt = 2;

void dfs (int i, int j) {
    map[i][j] = cnt;
    if (i != 0 && map[i - 1][j] == 1) dfs(i - 1, j);
    if (i != N - 1 && map[i + 1][j] == 1) dfs(i + 1, j);
    if (j != 0 && map[i][j - 1] == 1) dfs(i, j - 1);
    if (j != N - 1 && map[i][j + 1] == 1) dfs(i, j + 1);
    
    return;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < N; j++) map[i][j] = (temp[j] - '0');
    }
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (map[i][j] == 1) {
                dfs(i, j);
                cnt++;
            }
    
    cout << (cnt - 2) << "\n";
    
    int num[25 * 25 + 2];
    for (int i = 0; i < cnt; i++) num[i] = 0;
    num[0] = INF, num[1] = INF;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) num[map[i][j]]++;
    sort(num, num + cnt);
    for (int i = 0; i < cnt - 2; i++) cout << num[i] << "\n";
    
    return 0;
}