#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct binarynode {
    int val;
    int left = -1, right = -1;
};
struct binarynode tree[10000];

void insert (int chk, int pos) {
    if (tree[chk].val > tree[pos].val) {
        if (tree[chk].left == -1) {
            tree[chk].left = pos;
            return;
        }
        else insert(tree[chk].left, pos);
    } else {
        if (tree[chk].right == -1) {
            tree[chk].right = pos;
            return;
        }
        else insert(tree[chk].right, pos);
    }
    return;
}

void postorder (int pos) {
    if (tree[pos].left != -1) postorder(tree[pos].left);
    if (tree[pos].right != -1) postorder(tree[pos].right);
    cout << tree[pos].val << "\n";
    return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> tree[0].val;
	int i = 1;
    while (cin >> tree[i].val) {
        insert(0, i);
        i++;
    }
	
	postorder(0);
	
	return 0;
}
