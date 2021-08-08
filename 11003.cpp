#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>

using namespace std;

int n, l;
int* a;
deque< pair<int, int> > dq;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> l;
    a = new int[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    
    for (int i = 0; i < n; i++) {
        if (!dq.empty() && dq.front().second + l <= i)
            dq.pop_front();
        while (!dq.empty() && dq.back().first >= a[i])
            dq.pop_back();
        dq.push_back(make_pair(a[i], i));
        cout << dq.front().first << " ";
    }
    
    return 0;
}