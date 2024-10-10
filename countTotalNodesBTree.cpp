#include <bits/stdc++.h>
using namespace std;

class BTreeNode {
public:
    int val;
    BTreeNode* left;
    BTreeNode* right;

    BTreeNode(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

BTreeNode* levelOrderTreeInput() {
    int r;
    cin >> r;
    BTreeNode* root;
    if (r == -1) root = NULL;
    else root = new BTreeNode(r);

    queue<BTreeNode*> q;
    if (root) q.push(root);

    while (!q.empty()) {
        BTreeNode* parentNode = q.front();
        q.pop();

        int leftNodeVal, rightNodeVal;
        cin >> leftNodeVal >> rightNodeVal;

        BTreeNode* leftNode = nullptr;
        BTreeNode* rightNode = nullptr;

        if (leftNodeVal != -1) {
            leftNode = new BTreeNode(leftNodeVal);
            parentNode->left = leftNode;
            q.push(leftNode);
        }
        if (rightNodeVal != -1) {
            rightNode = new BTreeNode(rightNodeVal);
            parentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void levelOrderTreePrint(BTreeNode* root) {
    queue<BTreeNode*> q;
    if (root) q.push(root);

    while (!q.empty()) {
        BTreeNode* parentNode = q.front();
        q.pop();

        cout << parentNode->val << " ";

        if (parentNode->left) q.push(parentNode->left);
        if (parentNode->right) q.push(parentNode->right);
    }
}
int countNodeOfBinaryTree(BTreeNode* root){
    if(root==NULL) return 0;
    int totalLeftNodes=countNodeOfBinaryTree(root->left);
    int totalRightNodes=countNodeOfBinaryTree(root->right);
    return totalLeftNodes+totalRightNodes+1;
}
int main() {
    BTreeNode* root = levelOrderTreeInput();
    // levelOrderTreePrint(root);
    int totalNodes=countNodeOfBinaryTree(root);
    cout<<totalNodes<<endl;
    return 0;
}
