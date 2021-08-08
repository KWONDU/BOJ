#include <iostream>

using namespace std;

int n, price[1000][3];

int min (int n1, int n2, int n3) {
    return min(n1, min(n2, n3));
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> price[i][0] >> price[i][1] >> price[i][2];

    int sum[1000][3];
    if (n == 1)
        for (int i = 0; i < 3; i++)
            sum[0][i] = price[0][i];
    else {
        for (int i = 0; i < 3; i++)
            sum[0][i] = price[0][i];
        
        for (int i = 1; i < n; i++) {
            sum[i][0] = min(sum[i - 1][1], sum[i - 1][2]) + price[i][0];
            sum[i][1] = min(sum[i - 1][2], sum[i - 1][0]) + price[i][1];
            sum[i][2] = min(sum[i - 1][0], sum[i - 1][1]) + price[i][2];
        }
    }
    
    int minsum = min(sum[n - 1][0], sum[n - 1][1], sum[n - 1][2]);
    cout << minsum;
    
    return 0;
}