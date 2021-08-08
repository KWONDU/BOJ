#include <iostream>
#include <vector>

using namespace std;

long long int K;

vector<long long int> dp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> K;
    
    dp.push_back(0);
    dp.push_back(1);
    long long int chk = 1;
    long long int len = 1;
    while (chk < K) {
        len++;
        dp.push_back(dp[len - 1] + dp[len - 2]);
        chk += dp[len];
    }
    dp.push_back(dp[len] + dp[len - 1]);
    
    while (len > 0) {
        if (len == 1) {
            if (K > 0) {
                cout << "1";
                return 0;
            } else {
                cout << "0";
                return 0;
            }
        }
        
        if (K >= dp[len + 1]) {
            K -= dp[len + 1];
            cout << "10";
            len -= 2;
        } else {
            cout << "0";
            len--;
        }
    }
    
    return  0;
}