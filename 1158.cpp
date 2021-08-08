#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    queue<int> q;
    for (int i = 1; i <= n; i++) q.push(i);
    
    cout << "<";
    int temp;
    while (q.size() > 1) {
        for (int i = 0; i < k - 1; i++) {
            temp = q.front();
            q.pop();
            q.push(temp);
        }
        temp = q.front(); cout << temp << ", ";
        q.pop();
    }
    cout << q.front() << ">";
    
	return 0;
}
