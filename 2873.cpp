#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int r, c;
    cin >> r >> c;
    
    if (r % 2 == 1) {
        for (int i = 0; i < r; i++) {
            if (i % 2 == 0)
                for (int j = 0; j < c - 1; j++)
                    cout << "R";
            else
                for (int j = 0; j < c - 1; j++)
                    cout << "L";
            
            if (i != r - 1)
                cout << "D";
        }
    }
    else if (c % 2 == 1) {
        for (int i = 0; i < c; i++) {
            if (i % 2 == 0)
                for (int j = 0; j < r - 1; j++)
                    cout << "D";
            else
                for (int j = 0; j < r - 1; j++)
                    cout << "U";
            
            if (i != c - 1)
                cout << "R";
        }
    }
    else {
        int temp, minvalue = 1001;
        pair<int, int> minpos = make_pair(-1, -1);
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++) {
                cin >> temp;
                if ((i + j) % 2 == 1 && temp < minvalue) {
                    minvalue = temp;
                    minpos.first = i;
                    minpos.second = j;
                }
            }
        
        for (int i = 0; i < minpos.first / 2; i++) {
            for (int j = 0; j < c - 1; j++)
                cout << "R";
            cout << "D";
            for (int j = 0; j < c - 1; j++)
                cout << "L";
            cout << "D";
        }
        
        for (int i = 0; i < minpos.second; i++) {
            if (i % 2 == 0)
                cout << "DR";
            else
                cout << "UR";
        }
        for (int i = minpos.second; i < c - 1; i++) {
            if (i % 2 == 0)
                cout << "RD";
            else
                cout <<"RU";
        }
        
        for (int i = 0; i < (r - 1 - minpos.first) / 2; i++) {
            cout << "D";
            for (int j = 0; j < c - 1; j++)
                cout << "L";
            cout << "D";
            for (int j = 0; j < c - 1; j++)
                cout << "R";
        }
    }
}