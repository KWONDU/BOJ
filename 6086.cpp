#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

const int sz = 52;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int c[sz][sz];
    int f[sz][sz];
    for (int i = 0; i < sz; i++)
        for (int j = 0; j < sz; j++) {
            c[i][j] = 0, f[i][j] = 0;
        }
    
    vector<int> pipe[sz];
    
    int n; cin >> n;
    char fromchar, tochar;
    int capacity, fromint, toint;
    for (int i = 0; i < n; i++) {
        cin >> fromchar >> tochar >> capacity;
        
        if ('A' <= fromchar && fromchar <= 'Z')
            fromint = fromchar - 'A';
        else
            fromint = fromchar - 'a' + 26;
        if ('A' <= tochar && tochar <= 'Z')
            toint = tochar - 'A';
        else
            toint = tochar - 'a' + 26;
        
        c[fromint][toint] += capacity;
        c[toint][fromint] += capacity;
        pipe[fromint].push_back(toint);
        pipe[toint].push_back(fromint);
    }
    
    int total = 0;
    
    int start = 0, finish = 'Z' - 'A';
    while (true) {
        int prev[sz];
        for (int i = 0; i < sz; i++) prev[i] = -1;
        
        queue<int> q;
        q.push(start);
        while (!q.empty() && prev[finish] == -1) {
            int pos = q.front();
            q.pop();
            for (int next: pipe[pos]) {
                if (prev[next] != -1) continue;
                
                if (c[pos][next] - f[pos][next] > 0) {
                    q.push(next);
                    prev[next] = pos;
                    if (next == finish) break;
                }
            }
        }
        
        if (prev[finish] == -1) break;
        
        int chk = finish;
        int flow = c[prev[chk]][chk] - f[prev[chk]][chk];
        while (prev[chk] != start) {
            chk = prev[chk];
            flow = min(flow, c[prev[chk]][chk] - f[prev[chk]][chk]);
        }
        
        chk = finish;
        while (chk != start) {
            f[prev[chk]][chk] += flow;
            f[chk][prev[chk]] -= flow;
            chk = prev[chk];
        }
        total += flow;
    }
    
    cout << total;
    
    return 0;
}