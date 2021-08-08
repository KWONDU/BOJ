#include <iostream>
#include <cmath>
#define PI 3.1415926535897932

using namespace std;

double R;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> R;

    cout << fixed;
    cout.precision(6);

    cout << (R * R) * PI << "\n" << (R * R) * 2;

    return 0;
}