#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

int N, num, cnt[10000 + 1];

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    
    memset(cnt, 0, sizeof(cnt));

    for (int i = 0; i < N; i++) {
        cin >> num;
        cnt[num]++;
    }

    for (int i = 1; i <= 10000; i++) {
        for (int j = 0; j < cnt[i]; j++) cout << i << "\n";
    }

    return 0;
}