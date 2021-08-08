#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> dict[26];
int cntConnect[26];

int N;
char word[100 + 1][10 + 1];

bool totalChk[26];

int usedCnt;
bool usedChk[26];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> word[i];
    
    for (int i = 0; i < 26; i++) cntConnect[i] = 0;
    
    usedCnt = 0;
    for (int i = 0; i < 26; i++) usedChk[i] = false;
    
    for (int i = 1; i < N; i++) {
        int j = 0;
        while (j < 10 && (word[i][j] - 'a') == (word[i + 1][j] - 'a')) {
            j++;
            if (word[i][j] == '\0') break;
            else if (word[i + 1][j] == '\0') {
                cout << "!";
                return 0;
            }
        }
        if (word[i][j] != '\0') {
            dict[word[i][j] - 'a'].push_back(word[i + 1][j] - 'a');
            cntConnect[word[i + 1][j] - 'a']++;
            
            if (!usedChk[word[i][j] - 'a']) {
                usedChk[word[i][j] - 'a'] = true;
                usedCnt++;
            }
            if (!usedChk[word[i + 1][j] - 'a']) {
                usedChk[word[i + 1][j] - 'a'] = true;
                usedCnt++;
            }
        }
    }
    
    queue<int> q;
    for (int i = 0; i < 26; i++)
        if (cntConnect[i] == 0 && !dict[i].empty()) q.push(i);
    
    vector<char> ans;
    while (!q.empty()) {
        if (q.size() > 1) {
            cout << "?";
            return 0;
        }
        
        int cur = q.front();
        q.pop();
        usedCnt--;
        ans.push_back((char)(cur + (int)'a'));
        
        for (int j : dict[cur]) {
            cntConnect[j]--;
            
            if (cntConnect[j] == 0) {
                q.push(j);
            }
        }
    }
    
    if (usedCnt > 0) {
        cout << "!";
        return 0;
    }
    
    for (int i = 0; i < 26; i++) totalChk[i] = false;
    for (int i = 1; i <= N; i++) {
        int j = 0;
        while (word[i][j] != '\0') {
            totalChk[word[i][j] - 'a'] = true;
            j++;
        }
    }
    
    int len = 0;
    for (int i = 0; i < 26; i++)
        if (totalChk[i]) len++;
    
    if (len == 1) {
        for (int i = 0; i < 26; i++)
            if (totalChk[i]) {
                cout << (char)(i + (int)'a');
                return 0;
            }
    } if (len > ans.size()) {
        cout << "?";
        return 0;
    }
    
    for (char c : ans) cout << c;
    
    return 0;
}