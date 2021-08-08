#include <iostream>
#include <vector>

using namespace std;

int A[1000];
int len[1000];
int par[1000];

int max (int x, int y) {
    return x > y ? x : y;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        len[i] = 1;
        par[i] = -1;
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j]) {
                if (len[i] < len[j] + 1) {
                    len[i] = len[j] + 1;
                    par[i] = j;
                }
            }
        }
    }
    
    int ansPos = -1;
    int ansLen = 0;
    for (int i = 0; i < N; i++) {
        if (len[i] > ansLen) {
            ansLen = len[i];
            ansPos = i;
        }
    }
    
    cout << ansLen << "\n";
    vector<int> ans;
    while (ansPos != -1) {
        ans.push_back(A[ansPos]);
        ansPos = par[ansPos];
    }
    for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << " ";
    
    return 0;
}