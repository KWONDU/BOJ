#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 20000 * 20000 + 20000 * 20000 + 1;

int n;
vector<pair<int ,int>> pos;

int min (int n1, int n2) {
    return n1 < n2 ? n1 : n2;
}

bool comp1 (pair<int, int> p1, pair<int, int> p2) {
    return p1.first < p2.first;
}

bool comp2 (pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;
}

int len (pair<int, int> p1, pair<int, int> p2) {
    return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
}

int lenX (pair<int, int> p1, pair<int, int> p2) {
    return (p1.first - p2.first) * (p1.first - p2.first);
}

int lenY (pair<int, int> p1, pair<int, int> p2) {
    return (p1.second - p2.second) * (p1.second - p2.second);
}

int minLen (int start, int finish) {
    if (start == finish) return INF;
    
    int mid = (start + finish) / 2;
    int leftLen = minLen(start, mid);
    int rightLen = minLen(mid + 1, finish);
    
    int compLen = min(leftLen, rightLen);
    
    vector<pair<int, int>> tempPos;
    
    int leftPos = mid, rightPos = mid;
    while (leftPos > start && lenX(pos[leftPos - 1], pos[mid]) < compLen) leftPos--;
    while (rightPos < finish && lenX(pos[mid], pos[rightPos + 1]) < compLen) rightPos++;
    for (int i = leftPos; i <= rightPos; i++) tempPos.push_back(pos[i]);
    
    sort(tempPos.begin(), tempPos.end(), comp2);
    
    for (int i = 0; i <= rightPos - leftPos; i++) {
        for (int j = i + 1; j <= rightPos - leftPos; j++) {
            if (lenY(tempPos[i], tempPos[j]) < compLen) {
                compLen = min(compLen, len(tempPos[i], tempPos[j]));
            } else break;
        }
    }
    
    return compLen;
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        pos.push_back(make_pair(x, y));
    }
    
    sort(pos.begin(), pos.end(), comp1);
    
    cout << minLen(0, n - 1);
    
    return 0;
}