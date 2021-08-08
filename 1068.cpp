#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef struct {
    int par;
    vector<int> child;
} node;

int cnt;

void find (node tree[], int pos) {
    if (tree[pos].child.size() == 0) {
        cnt++;
        return;
    }
    for (int i: tree[pos].child) find(tree, i);
    return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	node tree[50];
	int temp; for (int i = 0; i < n; i++) {
	    cin >> temp;
	    tree[i].par = temp;
	    tree[temp].child.push_back(i);
	}
	
	int del; cin >> del;
	int delpar = tree[del].par;
	if (delpar != -1)
	    for (int i = 0; i < tree[delpar].child.size(); i++)
	        if (tree[delpar].child[i] == del) {
	            tree[delpar].child.erase(tree[delpar].child.begin() + i);
	            tree[del].par = -1;
	            break;
	        }
	
	cnt = 0;
	for (int i = 0; i < n; i++)
	    if (tree[i].par == -1 && i != del) find(tree, i);
	cout << cnt;
	
	return 0;
}
