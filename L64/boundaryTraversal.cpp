#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left, * right;
};

void traverseLeft(Node* root, vector<int> &ans) {
    if((root == NULL) || (root -> left == NULL && root -> right == NULL)) {
        return;
    }
        
    ans.push_back(root -> data);
        
    if(root -> left) {
        traverseLeft(root -> left, ans);
    }
    else {
        traverseLeft(root -> right, ans);
    }
}
    
void traverseLeaf(Node* root, vector<int> &ans) {
    // Base case
    if(root == NULL) {
        return;
    }
    if(root -> left == NULL && root -> right == NULL) {
        ans.push_back(root -> data);
        return;
    }
        
    traverseLeaf(root -> left, ans);
    traverseLeaf(root -> right, ans);
}
    
void traverseRight(Node* root, vector<int> &ans) {
    // Base case
    if((root == NULL) || (root -> left == NULL && root -> right == NULL)) {
        return;
    }
    if(root -> right) {
        traverseRight(root -> right, ans);
    }
    else {
        traverseRight(root -> left, ans);
    }
        
    ans.push_back(root -> data);
}
    
vector <int> boundary(Node *root) {
    vector<int> ans;
        
    if(root == NULL) {
        return ans;
    }
        
    ans.push_back(root -> data);
        
    // Store left part
    traverseLeft(root -> left, ans);
        
    // Store leaf nodes
    // Left subtree
    traverseLeaf(root -> left, ans);
    // Right subtree
    traverseLeaf(root -> right, ans);
        
    // Store right part
    traverseRight(root -> right, ans);
        
    return ans;
}