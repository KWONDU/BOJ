#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <queue>

using namespace std;

bool sorting (pair<int, int> p1, pair<int, int> p2) {
    if (p1.first == p2.first) return p1.second < p2.second;
    else return p1.first < p2.first;
}

struct cmp {
    bool operator () (pair<int, int> p1, pair<int, int> p2) {
        if (p1.second == p2.second) return p1.first > p2.first;
        else return p1.second > p2.second;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    pair<int, int> classtime[200000];
    int s, t;
    for (int i = 0; i < n; i++) {
        cin >> s >> t;
        classtime[i] = make_pair(s, t);
    }
    
    sort(classtime, classtime + n, sorting);
    
    priority_queue<pair<int, int>, vector< pair<int, int> >, cmp> pq;
    
    for (int i = 0; i < n; i++) {
        if (!pq.empty() && pq.top().second <= classtime[i].first)
            pq.pop();
        pq.push(classtime[i]);
    }
    
    cout << pq.size();
    
    return 0;
}