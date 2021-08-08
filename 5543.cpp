#include <iostream>

using namespace std;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int hamO = 2001, drinkO = 2001;

    for (int i = 0; i < 3; i++) {
        int hamX;
        cin >> hamX;
        if (hamO > hamX) hamO = hamX;
    }

    for (int i = 0; i < 2; i++) {
        int drinkX;
        cin >> drinkX;
        if (drinkO > drinkX) drinkO = drinkX;
    }

    cout << hamO + drinkO - 50;

    return 0;
}