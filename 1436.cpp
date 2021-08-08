#include <iostream>
#include <string>

using namespace std;

int N;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    
    int num = 999;
    if (N == 1) num = 666;
    else {
        int cnt = 1;
        while (cnt < N) {
            num++;
            if (to_string(num).find("666") != string::npos) cnt++;
        }
    }

    cout << num;
    
    return 0;
}