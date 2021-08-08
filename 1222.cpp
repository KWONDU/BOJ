#include <iostream>

using namespace std;

int N;
int student[200000 + 1];

long long int d[2000000 + 1];

long long int max (long long int ll1, long long int ll2) {
    return ll1 > ll2 ? ll1 : ll2;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for (int i = 1; i <= 2000000; i++) d[i] = 0;
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> student[i];
        d[student[i]]++;
    }
    
    
    long long int ans = N;
    for (int i = 1; i <= 2000000; i++) {
        long long int cnt = 0;
        for (int j = i; j <= 2000000; j+=i) cnt += d[j];
        if (cnt >= 2) ans = max(ans, cnt * i);
    }
    
    cout << ans;
    
    return 0;
}