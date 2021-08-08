#include <iostream>
#include <string>

using namespace std;

int N;
string word;

int main () { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    int cnt = 0;
    while (N--) {
        cin >> word;
        
        bool flag = true, chk[26];
        for (int i = 0; i < 26; i++) chk[i] = false;
        int i = 0;
        while (i < word.length()) {
            if (chk[word[i] - 'a']) {
                flag = false;
                break;
            } else {
                int temp = i;
                while (temp < word.length() && word[temp] == word[i]) { temp++; }
                chk[word[i] - 'a'] = true;
                i = temp;
            }
        }
        
        if (flag) cnt++;
    }
    
    cout << cnt;
    
    return 0;
}