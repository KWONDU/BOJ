#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    bool set[21];
    for (int i = 0; i < 21; i++) set[i] = false;
    
    int m;
    cin >> m;
    while (m--) {
        string op;
        cin >> op;
        if (op == "all") {
            for (int i = 1; i <= 20; i++) set[i] = true;
        } else if (op == "empty") {
            for (int i = 1; i <= 20; i++) set[i] = false;
        } else {
            int x;
            cin >> x;
            if (op == "add") {
                set[x] = true;
            } else if (op == "remove") {
                set[x] = false;
            } else if (op == "check") {
                if (set[x]) cout << "1\n";
                else cout << "0\n";
            } else if (op == "toggle") {
                set[x] = !set[x];
            } else {
                cout << "wrong input";
                return 0;
            }
        }
    }
    
    return 0;
}