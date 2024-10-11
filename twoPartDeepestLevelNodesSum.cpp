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
    int rootNodeValue;
    cin >> rootNodeValue;
    BTreeNode* root;
    if (rootNodeValue == -1) root = NULL;
    else root = new BTreeNode(rootNodeValue);

    queue<BTreeNode*> q;
    if (root != NULL) q.push(root);

    while (!q.empty()) {
        BTreeNode* parentNode = q.front();
        q.pop();

        int leftNodeValue, rightNodeValue;
        cin >> leftNodeValue >> rightNodeValue;

        BTreeNode* leftNode = NULL;
        BTreeNode* rightNode = NULL;

        if (leftNodeValue != -1) leftNode = new BTreeNode(leftNodeValue);
        if (rightNodeValue != -1) rightNode = new BTreeNode(rightNodeValue);

        parentNode->left = leftNode;
        parentNode->right = rightNode;

        if (leftNode) q.push(leftNode);
        if (rightNode) q.push(rightNode);
    }
    return root;
}
int maxHeightOfBTree(BTreeNode* root) {
    if (root == NULL) return 0;
    int leftSubTreeHeight = maxHeightOfBTree(root->left);
    int rightSubTreeHeight = maxHeightOfBTree(root->right);
    return max(leftSubTreeHeight, rightSubTreeHeight) + 1;
}
int deepestLeavesNodeSum(BTreeNode* root) {
    if (root == NULL) return 0;
    int treeHeight = maxHeightOfBTree(root);
    int deepestNodeSum = 0;
    queue<pair<BTreeNode*, int>> q;
    q.push({root, 1});
    
    while (!q.empty()) {
        auto parentNode = q.front();
        q.pop();

        if (parentNode.second == treeHeight) 
            deepestNodeSum += parentNode.first->val;

        if (parentNode.first->left) 
            q.push({parentNode.first->left, parentNode.second + 1});
        if (parentNode.first->right) 
            q.push({parentNode.first->right, parentNode.second + 1});
    }
    return deepestNodeSum;
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
    return;
}
void outerRightOfBTreePrint(BTreeNode* root){
    if(root==NULL) return;
    cout<<root->val<<" "; //staright
    outerRightOfBTreePrint(root->right);
    cout<<root->val<<" "; //reverse
}
int maxDiameter=0;
int diameterOfBTree(BTreeNode* root){
    if(root==NULL) return 0;
    int leftSubTreeHeight=diameterOfBTree(root->left);
    int rightSubTreeHeight=diameterOfBTree(root->right);
    int diametreOfEveryNode=rightSubTreeHeight+leftSubTreeHeight;
    maxDiameter=max(maxDiameter, diametreOfEveryNode);
    return max(rightSubTreeHeight, leftSubTreeHeight)+1;

}
int tiltSum = 0;
int calculateTilt(BTreeNode* root) {
    if (root == NULL) return 0;
    int leftSum = calculateTilt(root->left);
    int rightSum = calculateTilt(root->right);
    int currentTilt = abs(leftSum - rightSum);
    tiltSum += currentTilt;
    return leftSum + rightSum + root->val;
}
int leftSubTreeDeepestNode;
int rightSubTreeDeepestNode;

int maxHeightOfBTree(BTreeNode* root, bool isLeftSubtree) {
    if (root == NULL) return 0;
    int leftSubTreeHeight = maxHeightOfBTree(root->left, isLeftSubtree);
    int rightSubTreeHeight = maxHeightOfBTree(root->right, isLeftSubtree);
    int currentHeight = max(leftSubTreeHeight, rightSubTreeHeight) + 1;
    if (root->left == NULL && root->right == NULL) {
        if (isLeftSubtree) {
            leftSubTreeDeepestNode = root->val;
        } else {
            rightSubTreeDeepestNode = root->val;
        }
    }

    return currentHeight;
}

void findDeepestNodes(BTreeNode* root) {
    maxHeightOfBTree(root->left, true);
    maxHeightOfBTree(root->right, false);
}

int main() {
    BTreeNode* root = levelOrderTreeInput();
    findDeepestNodes(root);
    cout<<leftSubTreeDeepestNode<<" "<<rightSubTreeDeepestNode;
    return 0;
}
