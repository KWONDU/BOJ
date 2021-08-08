#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m; cin >> n >> m;
        
        int* arr = new int[n];
        for (int j = 0; j < n; j++) cin >> arr[j];
        
        queue< pair<int, bool> > q;
        for (int j = 0; j < n; j++) {
            if (j == m)
                q.push(make_pair(arr[j], true));
            else
                q.push(make_pair(arr[j], false));
        }
        
        sort(arr, arr + n);
        
        int cnt = 0;
        pair<int, bool> temp;
        bool chk;
        for (int j = n - 1; j >= 0; j--) {
            while (q.front().first != arr[j]) {
                temp = make_pair(q.front().first, q.front().second);
                q.pop();
                q.push(temp);
            }
            chk = q.front().second;
            q.pop();
            cnt++;
            if (chk) break;
        }
        
        cout << cnt << "\n";
    }
    
	return 0;
}
