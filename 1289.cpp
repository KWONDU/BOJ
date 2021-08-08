#include <iostream>
#include <vector>

using namespace std;

const long long int mod = 1000000007;

int N;
vector<pair<int, long long int>> tree[100000 + 1];

long long int ans = 0;

long long int weight (int cur, int par) {
    long long int prevSum = 1;
    for (auto child: tree[cur]) {
        if (child.first == par) continue;
        long long int c = (child.second * weight(child.first, cur)) % mod;
        ans = (ans + (prevSum * c) % mod) % mod;
        prevSum = (prevSum + c) % mod;
    }
    return prevSum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int A, B;
        long long int W;
        cin >> A >> B >> W;
        tree[A].push_back(make_pair(B, W));
        tree[B].push_back(make_pair(A, W));
    }
    
    weight(1, -1);
    cout << ans;
    
    return  0;
}