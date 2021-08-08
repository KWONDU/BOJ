#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string tempN;
vector<char> N;

bool comp (char c1, char c2) {
    return (c1 - '0') > (c2 - '0') ? true : false;
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> tempN;
    for (int i = 0; i < tempN.length(); i++) N.push_back(tempN[i]);

    sort(N.begin(), N.end(), comp);
    for (char i : N) cout << i;
    
    return 0;
}