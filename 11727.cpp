#include <iostream>

using namespace std;

const int mod = 10007;
int cnt[1001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;
    
    cnt[1] = 1;
    cnt[2] = 3;
    for (int i = 3; i <= n; i++)
        cnt[i] = (cnt[i - 1] + cnt[i - 2] * 2) % mod;
    
    cout << cnt[n];
    
    return 0;
}