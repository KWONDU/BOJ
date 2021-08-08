#include <iostream>
#include <vector>

using namespace std;

vector<int> prime;

int N;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    bool isPrime[4000000 + 1];
    for (int i = 1; i <= 4000000; i++) isPrime[i] = true;
    isPrime[1] = false;
    for (int i = 2; i <= 4000000; i++) {
        if (!isPrime[i]) continue;
        prime.push_back(i);
        for (int j = i * 2; j <= 4000000; j+=i) isPrime[j] = false;
    }
    
    cin >> N;
    
    auto iter1 = prime.begin();
    auto iter2 = prime.begin();
    
    int cnt = 0, sum = *iter2;
    while (iter1 != prime.end() && iter2 != prime.end()) {
        if (*iter1 > N || *iter2 > N) break;
        
        if (sum < N) {
            iter2++;
            sum += *iter2;
        } else if (sum == N) {
            cnt++;
            sum -= *iter1;
            iter1++;
        } else {
            sum -= *iter1;
            iter1++;
        }
    }
    
    cout << cnt;
    
    return 0;
}