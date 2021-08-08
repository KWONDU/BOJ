#include <iostream>
#include <vector>

using namespace std;

int a, r, mod;

long long int powR (int n) {
    if (n == 0) return 1;
    
    long long int powRN2 = powR(n / 2);
    long long int temp = (powRN2 * powRN2) % mod;
    if (n % 2 == 0) return temp;
    else return (temp * r) % mod;
}

long long int ans (int n) {
    if (n == 1) return 1;
    
    int divN = n / 2;
    long long int powRN = powR(divN);
    long long int ansN2 = ans(divN);
    
    if (n % 2 == 0) return (ansN2 * (powRN + 1)) % mod;
    else {
        int temp = (ansN2 * ((powRN * r) % mod + 1)) % mod;
        return (temp + powRN) % mod;
    }
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> a >> r >> n >> mod;
    
    cout << (ans(n) * a) % mod;
    
    return 0;
}