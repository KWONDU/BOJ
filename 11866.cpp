#include <iostream>
#include <queue>

using namespace std;

int N, K;
queue<int> q;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;

    cout << "<";
    for (int i = 1; i <= N; i++) q.push(i);
    while (q.size() > 1) {
        for (int i = 0; i < K - 1; i++) {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        cout << q.front() << ", ";
        q.pop();
    }
    cout << q.front() << ">";
    q.pop();

    return 0;
}