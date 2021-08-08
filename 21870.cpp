#include <iostream>

using namespace std;

int N;
int a[200000 + 1];

long long int max (long long int ll1, long long int ll2) {
    return ll1 > ll2 ? ll1 : ll2;
}

int gcd (int n1, int n2) {
    while (n1 != 0 && n2 != 0) {
        if (n1 > n2) n1 %= n2;
        else n2 %= n1;
    }
    
    if (n1 == 0) return n2;
    else return n1;
}

int manyGCD (int start, int finish) {
    if (start == finish) return a[start];
    
    int ret = gcd(a[start], a[start + 1]);
    for (int i = start + 2; i <= finish; i++) ret = gcd(ret, a[i]);
    return ret;
}

long long int beau (int start, int finish) {
    if (start == finish) return a[start];
    
    int divLen = (finish - start + 1) / 2;
    long long int leftGCD = beau(start, start + divLen - 1);
    long long int rightGCD = beau(start + divLen, finish);
    
    return max(leftGCD + manyGCD(start + divLen, finish), manyGCD(start, start + divLen - 1) + rightGCD);
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> a[i];
    
    cout << beau(1, N);
    
    return 0;
}