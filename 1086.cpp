#include <iostream>
#include <memory.h>
#include <string>

using namespace std;

long long int p, q, gcd, dp[1<<15][100];   // bit mask i에 대해 나머지가 j인 개수

int N, K, arr[15], len[15], powerTen[50 + 1];
string tempStr[15];

long long int max (long long int ll1, long long int ll2) {
    return ll1 > ll2 ? ll1 : ll2;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> tempStr[i];
    cin >> K;
    
    for (int i = 0; i < N; i++) {
        len[i] = tempStr[i].size();
        int temp = 0;
        for (int j = 0; j < len[i]; j++)
            temp = (temp * 10 + (tempStr[i][j] - '0')) % K;
        arr[i] = temp;
    }
    
    powerTen[0] = 1 % K;
    for (int i = 1; i <= 50; i++) powerTen[i] = (powerTen[i - 1] * 10) % K;
    
    for (int i = 0; i < 1<<15; i++) memset(dp[i], 0, sizeof(dp[i]));
    
    for (int i = 0; i < N; i++) dp[1<<i][arr[i]] = 1;
    
    for (int mask = 0; mask < 1<<N; mask++) {
        for (int re = 0; re < K; re++) {
            for (int i = 0; i < N; i++) {
                if (!(mask & 1<<i)) {
                    dp[mask | 1<<i][((re * powerTen[len[i]]) % K + arr[i]) % K] += dp[mask][re];
                }
            }
        }
    }
    
    p = dp[(1<<N) - 1][0];
    q = 1;
    for (int i = 1; i <= N; i++) q *= i;
    
    long long int tempP = p;
    long long int tempQ = q;
    
    while (tempP > 0 && tempQ > 0) {
        if (tempP > tempQ) tempP %= tempQ;
        else tempQ %= tempP;
    }
    gcd = max(tempP, tempQ);
    
    cout << (p / gcd) << "/" << (q / gcd);
    
    return 0;
}