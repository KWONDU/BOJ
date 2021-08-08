#include <iostream>
#include <string>

using namespace std;

int N;
string num;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> num;
    
    int ans = 0;
    for (int i = 0; i < num.length(); i++) {
        ans += (num[i] - '0');
    }

    cout << ans;

    return 0;
}