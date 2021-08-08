#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector<int> coor;
    vector<int> x_prime;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        coor.push_back(temp);
        x_prime.push_back(temp);
    }
    
    sort(coor.begin(), coor.end());
    
    coor.erase(unique(coor.begin(), coor.end()), coor.end());
    
    for (int i = 0; i < n; i++)
        cout << (lower_bound(coor.begin(), coor.end(), x_prime[i]) - coor.begin()) << " ";
    
    return 0;
}