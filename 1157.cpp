#include <iostream>
#include <string>

using namespace std;

string word;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> word;

    int cnt[26]; for (int i = 0; i < 26; i++) cnt[i] = 0;
    for (int i = 0; i < word.length(); i++) {
        if (word[i] - 'a' >= 0) cnt[word[i] - 'a']++;
        else cnt[word[i] - 'A']++;
    }

    int maxVal = cnt[0];
    int pos = 0;
    for (int i = 1; i < 26; i++)
        if (maxVal < cnt[i]) {
            maxVal = cnt[i];
            pos = i;
        }
    int chk = 0;
    for (int i = 0; i < 26; i++)
        if (maxVal == cnt[i])
            chk++;
    
    if (chk > 1) cout << "?";
    else cout << (char)(pos + 65);

    return 0;
}