#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef struct {
    int par;
    vector<int> child;
} node;

node* tree;

void set (int par, int child) {
    tree[child].par = par;
    for (int i: tree[child].child)
        if (i != par) set(child, i);
    return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	tree = new node[n + 1];
	int temp1, temp2;
	for (int i = 0; i < n - 1; i++) {
	    cin >> temp1 >> temp2;
	    tree[temp1].child.push_back(temp2);
	    tree[temp2].child.push_back(temp1);
	}
	
	tree[1].par = -1;
    set(-1, 1);
	
	for (int i = 2; i <= n; i++) cout << tree[i].par << "\n";
	
	return 0;
}
