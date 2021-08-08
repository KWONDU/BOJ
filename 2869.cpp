#include <iostream>

using namespace std;

int A, B, V;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> A >> B >> V;

    int day = (V - A) / (A - B) + 1;
    if ((V - A) % (A - B) != 0) day++;

    cout << day;

    return 0;
}