#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N;
string word[20000];

bool comp (string s1, string s2) {
    if (s1.length() == s2.length()) {
        return s1.compare(s2) < 0 ? true : false;
    } else return s1.length() < s2.length();
}

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> word[i];

    sort(word, word + N, comp);
    for (int i = 0; i < N; i++) {
        if (i > 0 && word[i - 1] == word[i]) continue;
        cout << word[i] << "\n";
    }
    
    return 0;
}