#include <iostream>
#include <queue>

using namespace std;

int N;
queue<int> q;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    
    for (int i = 1; i <= N; i++) q.push(i);
    while (q.size() > 1) {
        q.pop();
        int temp = q.front();
        q.pop();
        q.push(temp);
    }

    cout << q.front();

    return 0;
}