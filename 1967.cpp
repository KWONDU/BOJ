#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct node {
    vector<int> child;
    vector<int> weight;
};
struct node* tree;

int ans, x = 0, y = 0;
void find (int par, int pos, int len) {
    if (ans < len) {
        ans = len;
        y = pos;
    }
    
    for (int i = 0; i < tree[pos].child.size(); i++)
        if (tree[pos].child[i] != par) {
            find(pos, tree[pos].child[i], len + tree[pos].weight[i]);
        }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	tree = new struct node[n + 1];
	
	int temp1, temp2, temp3;
	for (int i = 0; i < n - 1; i++) {
	    cin >> temp1 >> temp2 >> temp3;
	    tree[temp1].child.push_back(temp2);
	    tree[temp1].weight.push_back(temp3);
	    tree[temp2].child.push_back(temp1);
	    tree[temp2].weight.push_back(temp3);
	}
	
	ans = 0;
	find(-1, 1, 0);
	x = y;
	find(-1, x, 0);
	cout << ans;
	
	return 0;
}
