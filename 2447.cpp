#include <iostream>

using namespace std;

int N;

char pattern[6561][6561];

void func (int x, int y, int len) {
    if (len == 1) pattern[x][y] = '*';
    else
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (i != 1 || j != 1)
                    func(x + (len / 3) * i, y + (len / 3) * j, len / 3);
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) pattern[i][j] = ' ';
    func(0, 0, N);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cout << pattern[i][j];
        cout << endl;
    }
    
    return 0;
}