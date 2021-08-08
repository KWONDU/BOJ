#include <iostream>

using namespace std;

int pow(int base, int exp) {
    if (exp == 0) return 1;
    return pow(base, exp - 1) * base;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, r, c;
    cin >> n >> r >> c;
    
    int cnt = 0;
    while (n--) {
        int power = pow(2, n);
        cnt += power * power * (r / power * 2 + c / power);
        r %= power;
        c %= power;
    }
    
    cout << cnt << "\n";
    
    return 0;
}