#include <iostream>
#include <string>

using namespace std;

string word;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> word;

    int cnt = 0, i = 0;
    while (i < word.length()) {
        if (i < word.length() - 1 && word[i] == 'c' && word[i + 1] == '=') i += 2;
        else if (i < word.length() - 1 && word[i] == 'c' && word[i + 1] == '-') i += 2;
        else if (i < word.length() - 2 && word[i] == 'd' && word[i + 1] == 'z' && word[i + 2] == '=') i += 3;
        else if (i < word.length() - 1 && word[i] == 'd' && word[i + 1] == '-') i += 2;
        else if (i < word.length() - 1 && word[i] == 'l' && word[i + 1] == 'j') i += 2;
        else if (i < word.length() - 1 && word[i] == 'n' && word[i + 1] == 'j') i += 2;
        else if (i < word.length() - 1 && word[i] == 's' && word[i + 1] == '=') i += 2;
        else if (i < word.length() - 1 && word[i] == 'z' && word[i + 1] == '=') i += 2;
        else i += 1;
        cnt++;
    }

    cout << cnt;

    return 0;
}