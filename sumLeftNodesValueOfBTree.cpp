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
int countLeafNodeOfBinaryTree(BTreeNode* root){
    //check the tree empty or not
    if(root==NULL) return 0;
    
    if(root->left==NULL && root->right==NULL) return 1;
    int totalLeftLeafNodes=countLeafNodeOfBinaryTree(root->left);
    int totalRightLeafNodes=countLeafNodeOfBinaryTree(root->right);
    return totalLeftLeafNodes+totalRightLeafNodes;
}
int maxHeightOfBTree(BTreeNode* root){
    if(root==NULL) return 0;
    int leftHeight=maxHeightOfBTree(root->left);
    int rightHeight=maxHeightOfBTree(root->right);
    int maxHeight=max(leftHeight, rightHeight)+1; //currentNode er height 1 hoy.
    return maxHeight;
}
int sum=0;
void sumLeftNodesValuesOfBTree(BTreeNode* root){
    if(root==NULL) return;
    if(root->left!=NULL) sum+=root->left->val;
    sumLeftNodesValuesOfBTree(root->left);
    sumLeftNodesValuesOfBTree(root->right);
}
int main() {
    BTreeNode* root = levelOrderTreeInput();
    // levelOrderTreePrint(root);
    // int totalLeafNodes=countLeafNodeOfBinaryTree(root);
    // int maxHeight=maxHeightOfBTree(root);
    // cout<<maxHeight<<endl;
    sum=0; //reassign for every testcase
    sumLeftNodesValuesOfBTree(root);
    cout<<sum<<endl;
    return 0;
}
