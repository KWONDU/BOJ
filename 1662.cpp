#include <iostream>
#include <string>
#include <stack>

using namespace std;

string S;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> S;
    
    stack<int> len;
    len.push(0);
    for (int i = S.length() - 1; i >= 0; i--) {
        if ('0' <= S[i] && S[i] <= '9') {
            int temp = len.top();
            len.pop();
            len.push(++temp);
        } else if (S[i] == '(') {
            int mul = S[--i] - '0';
            int temp1 = len.top();
            len.pop();
            temp1 *= mul;
            int temp2 = len.top();
            len.pop();
            len.push(temp1 + temp2);
        } else len.push(0);
    }
    
    cout << len.top();
    
    return 0;
}