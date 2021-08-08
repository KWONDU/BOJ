#include <iostream>
#include <string>

using namespace std;

string word;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> word;

    int time = 0;
    for (char i : word) {
        if (i == 'A' || i == 'B' || i == 'C') time += 3;
        else if (i == 'D' || i == 'E' || i == 'F') time += 4;
        else if (i == 'G' || i == 'H' || i == 'I') time += 5;
        else if (i == 'J' || i == 'K' || i == 'L') time += 6;
        else if (i == 'M' || i == 'N' || i == 'O') time += 7;
        else if (i == 'P' || i == 'Q' || i == 'R' || i == 'S') time += 8;
        else if (i == 'T' || i == 'U' || i == 'V') time += 9;
        else time += 10;
    }

    cout << time;

    return 0;
}