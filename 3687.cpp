#include <iostream>
#include <string>

using namespace std;

/*
2 : 1
3 : 7
4 : 4
5 : 2, 3, 5
6 : 0, 6, 9
7 : 8
*/

long long int minDP[100 + 1] = {0, 0, 1, 7, 4, 2, 6, 8, 10, 0};

long long int min (long long int n1, long long int n2) {
    return n1 < n2 ? n1 : n2;
}

long long int power (int base, int exponent) {
    if (exponent == 0) return 1;
    return base * power(base, exponent - 1);
}

long long int combine (long long int n1, long long int n2) {
    long long int temp = n2;
    int len = 0;
    while (temp > 0) {
        temp /= 10;
        len++;
    }
    if (n2 == 0) len++;
    
    return n1 * power(10, len) + n2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    for (int i = 9; i <= 100; i++) {
        minDP[i] = combine(minDP[i - 2], minDP[2]);
        for (int j = 3; j <= 7; j++) {
            if (j == 6) minDP[i] = min(minDP[i], combine(minDP[i - 6], 0));
            else minDP[i] = min(minDP[i], combine(minDP[i - j], minDP[j]));
        }
    }
    
    int chk;
    cin >> chk;
    while (chk--) {
        int n;
        cin >> n;
        
        string maxNum = "";
        
        int tempMax = n;
        if (n % 2 == 1) {
            maxNum += "7";
            tempMax -= 2;
        }
        for (int i = 0; i < tempMax / 2; i++) maxNum += "1";
        
        cout << minDP[n] << " " << maxNum << endl;
    }
    
    return  0;
}