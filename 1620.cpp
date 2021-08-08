#include <iostream>
#include <string>
#include <utility>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    map<string, int> findInt;
    map<int, string> findString;
    
    for (int i = 0; i < n; i++) {
        string pokemon;
        cin >> pokemon;
        findInt.insert(make_pair(pokemon, i + 1));
        findString.insert(make_pair(i + 1, pokemon));
    }
    
    while (m--) {
        string qs;
        cin >> qs;
        if ('0' <= qs.at(0) && qs.at(0) <= '9') {
            cout << findString[stoi(qs)] << "\n";
        } else {
            cout << findInt[qs] << "\n";
        }
    }
    
    return 0;
}