#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    int x[100000];
    int p[100000];
    for (int i = 0; i < n; i++)
        cin >> x[i] >> p[i];
    
    int money = 0;
    bool chk = false;
    int maxreward = 0;
    int except = 0;
    for (int i = 0; i < n; i++) {
        if (money - except <= x[i]) {
            money += p[i];
            if (maxreward < p[i])
                maxreward = p[i];
        }
        else {
            if (chk) {
                cout << "Zzz";
                return 0;
            }
            else if (i == n - 1) {
                cout << "Kkeo-eok";
                return 0;
            }
            
            if (maxreward > p[i]) {
                except = maxreward;
                if (money - except > x[i])
                    except = p[i];
            }
            else
                except = p[i];
            chk = true;
            money += p[i];
        }
    }
    
    cout << "Kkeo-eok";
}