#include <iostream>

using namespace std;

int A, B, C;

int cal (int b) {
    if (b == 0) return 1;
    else {
        long long int x = cal(b / 2);
        x = (x * x) % C;
        if (b % 2 == 0) return x;
        else return (x * A) % C;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> A >> B >> C;
    cout << cal(B);
    
    return 0;
}