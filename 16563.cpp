#include <iostream>
#include <vector>

using namespace std;

bool chk[2236 + 1]; // 2236^2 = 4999696, 2237^2 = 5004169
vector<int> prime;

int N;
int k[1000000 + 1];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> k[i];
    
    for (int i = 1; i * i <= 5000000; i++) chk[i] = true;
    for (int i = 2; i * i <= 5000000; i++) {
        if (!chk[i]) continue;
        
        prime.push_back(i);
        int j = i * i;
        while (j <= 2236) {
            chk[j] = false;
            j += i;
        }
    }
    
    for (int i = 1; i <= N; i++) {
        int num = k[i], pos = 0;
        while (num > 1 && pos < prime.size() && prime[pos] * prime[pos] <= k[i]) {
            if (num % prime[pos] == 0) {
                cout << prime[pos] << " ";
                num /= prime[pos];
            } else pos++;
        }
        if (num > 1) cout << num;
        cout << "\n";
    }
    
    return 0;
}