#include <iostream>

using namespace std;

char chk[531441];

int power3[13];

void cantor (int start, int n) {
    if (n == 0) chk[start] = '-';
    else {
        cantor(start, n - 1);
        cantor(start + 2 * power3[n - 1], n - 1);
    }
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    power3[0] = 1;
    for (int i = 1; i <= 12; i++) power3[i] = power3[i - 1] * 3;
    
    int N;
    while (true) {
        cin >> N;
        if (cin.eof()) break;
        
        for (int i = 0; i < power3[N]; i++) chk[i] = ' ';
        cantor(0, N);
        for (int i = 0; i < power3[N]; i++) cout << chk[i];
        cout << endl;
    }
    
    return 0;
}