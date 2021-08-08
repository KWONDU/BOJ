#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node (int data) : data(data), left(NULL), right(NULL) {}
};

void postorder (Node* v) {
    if (v->left != NULL) postorder(v->left);
    if (v->right != NULL) postorder(v->right);
    cout << v->data << " ";
}

int T, n;
int pre[1000 + 1], in[1000 + 1];

Node* makeTree (int low, int high, int chk) {
    if (low > high) return NULL;
    
    Node* root = new Node(pre[chk]);
    
    int pos = low;
    while (pos < high) {
        if (in[pos] == pre[chk]) break;
        else pos++;
    }
    
    root->left = makeTree(low, pos - 1, chk + 1);
    root->right = makeTree(pos + 1, high, pos - low + chk + 1);
    return root;
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> pre[i];
        for (int i = 1; i <= n; i++) cin >> in[i];
        
        Node* bt = makeTree(1, n, 1);
        
        postorder(bt);
        cout << endl;
    }
    
    return 0;
}