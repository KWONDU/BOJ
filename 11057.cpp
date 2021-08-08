#include <iostream>

int main () {
    int n;
    std::cin >> n;
    
    int sum = 0;
    const int mod = 10007;
    
    int temp[1000+1][10];
    for (int j = 0; j < 10; j++) temp[1][j] = 1;
    for (int i = 2; i <= 1000; i++)
        for (int j = 0; j < 10; j++) {
            int tempsum = 0;
            for (int k = 0; k <= j; k++)
                tempsum = (tempsum + temp[i - 1][k]) % mod;
            temp[i][j] = tempsum;
        }
    
    for (int j = 0; j < 10; j++) sum = (sum + temp[n][j]) % mod;
    
    std::cout << sum;
    
    return 0;
}