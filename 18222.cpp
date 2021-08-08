#include <iostream>
#include <vector>

using namespace std;

long long int k;

vector<long long int> pow2;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> k;
    
    pow2.push_back(1);
    long long int pow2Cal = 1;
    while (pow2Cal * 2 <= k) {
        pow2Cal *= 2;
        pow2.push_back(pow2Cal);
    }
    
    long long int temp = k;
    int x = 0;
    while (temp > 1) {
        temp /= 2;
        x++;
    }
    
    int reverse = 0;
    while (x > 0) {
        if (k > pow2[x]) {
            k -= pow2[x--];
            reverse++;
        } else x--;
    }
    
    if (reverse % 2 == 0) cout << (k - 1);
    else cout << (1 - (k - 1));
    
    return 0;
}