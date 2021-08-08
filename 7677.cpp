#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    const int mod = 1e4;
    
    int fib[30][4];
    fib[0][0] = 1; fib[0][1] = 1; fib[0][2] = 1; fib[0][3] = 0;
    for (int i = 1; i < 30; i++) {
        fib[i][0] = (fib[i - 1][0] * fib[i - 1][0] + fib[i - 1][1] * fib[i - 1][2]) % mod;
        fib[i][1] = (fib[i - 1][0] * fib[i - 1][1] + fib[i - 1][1] * fib[i - 1][3]) % mod;
        fib[i][2] = (fib[i - 1][2] * fib[i - 1][0] + fib[i - 1][3] * fib[i - 1][2]) % mod;
        fib[i][3] = (fib[i - 1][2] * fib[i - 1][1] + fib[i - 1][3] * fib[i - 1][3]) % mod;
    }
    
    int n;
    while (true) {
        cin >> n;
        if (n == -1) break;
        else if (n == 0) {
            cout << "0\n";
            continue;
        }
        
        int tempbinary;
        vector<bool> binary;
        while (n > 0) {
            tempbinary = n % 2;
            if (tempbinary == 0)
                binary.push_back(false);
            else
                binary.push_back(true);
            n /= 2;
        }
        
        int temp[4];
        int ans[4] = {1, 0, 1, 0};
        for (int i = 0; i < binary.size(); i++) {
            if (!binary[i])
                continue;
            
            temp[0] = (ans[0] * fib[i][0] + ans[1] * fib[i][2]) % mod;
            temp[1] = (ans[0] * fib[i][1] + ans[1] * fib[i][3]) % mod;
            temp[2] = (ans[2] * fib[i][0] + ans[3] * fib[i][2]) % mod;
            temp[3] = (ans[2] * fib[i][1] + ans[3] * fib[i][3]) % mod;
            for (int i = 0; i < 4; i++) ans[i] = temp[i];
        }
        cout << ans[1] << "\n";
    }
    
    return 0;
}