#include <iostream>
#include <memory.h>
#include <string>

using namespace std;

bool dp[1000000 + 1];

int N, cur;
string tempStr;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    memset(dp, false, sizeof(dp));
    
    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        tempStr = to_string(i);
        for (int len = 1; len < tempStr.size(); len++) {    // len = tempStr.size() 인 경우 제외
            for (int start = 0; start <= tempStr.size() - len; start++) {
                cur = stoi(tempStr.substr(start, len));
                if (cur == 0) continue;
                dp[i] = dp[i] | !dp[i - cur];
            }
        }
    }
    
    if (!dp[N]) {
        cout << "-1";
        return 0;
    }
    
    tempStr = to_string(N);
    
    int ans = 1000000 + 1;
    for (int len = 1; len < tempStr.size(); len++) {
        for (int start = 0; start <= tempStr.size() - len; start++) {
            cur = stoi(tempStr.substr(start, len));
            if (cur != 0 && !dp[N - cur]) ans = min(ans, cur);
        }
    }
    
    cout << ans;
    
    return 0;
}