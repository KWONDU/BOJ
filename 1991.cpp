#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct binarynode {
    int par = -1;
    int left = -1, right = -1;
};
struct binarynode* tree;

void preorder (int pos) {
    if (pos == -1) return;
    
    cout << (char)(pos + 65);
    preorder(tree[pos].left);
    preorder(tree[pos].right);
}

void inorder (int pos) {
    if (pos == -1) return;
    
    inorder(tree[pos].left);
    cout << (char)(pos + 65);
    inorder(tree[pos].right);
}

void postorder (int pos) {
    if (pos == -1) return;
    
    postorder(tree[pos].left);
    postorder(tree[pos].right);
    cout << (char)(pos + 65);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	tree = new struct binarynode[n];
	
	char par, left, right;
	for (int i = 0; i < n; i++) {
	    cin >> par >> left >> right;
	    if (left != '.') {
	        tree[par - 'A'].left = left - 'A';
	        tree[left - 'A'].par = par - 'A';
	    }
	    if (right != '.') {
	        tree[par - 'A'].right = right - 'A';
	        tree[right - 'A'].par = par - 'A';
	    }
	}
	
	preorder(0);
	cout << "\n";
	inorder(0);
	cout << "\n";
	postorder(0);
	
	return 0;
}
