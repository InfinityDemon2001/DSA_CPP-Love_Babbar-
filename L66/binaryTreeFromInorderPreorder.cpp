#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
};

// Approach 1
int findPosition(int in[], int element, int n) {
    for(int i = 0; i < n; i ++) {
        if(in[i] == element) {
            return i;
        }
    }
        
    return -1;
}
    
Node* solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n) {
    // Base case
    if(index >= n || inorderStart > inorderEnd) {
        return NULL;
    }
        
    int element = pre[index ++];
        
    Node* root = new Node(element);
        
    int position = findPosition(in, element, n);
        
    // Recursive calls
    root -> left = solve(in, pre, index, inorderStart, position - 1, n);
    root -> right = solve(in, pre, index, position + 1, inorderEnd, n);
        
    return root;
}
    
Node* buildTree(int in[],int pre[], int n) {
    int preOrderIndex = 0;
        
    Node* ans = solve(in, pre, preOrderIndex, 0, n - 1, n);
        
    return ans;
}

// Approach 2
void createMapping(int in[], map<int, int> &nodeToIndex, int n) {
    for(int i = 0; i < n; i ++) {
        nodeToIndex[in[i]] = i;
    }
}
    
Node* solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n, map<int, int> &nodeToIndex) {
    // Base case
    if(index >= n || inorderStart > inorderEnd) {
        return NULL;
    }
        
    // Create a root node for element
    int element = pre[index ++];
    Node* root = new Node(element);
        
    // Find element's position in inorder
    int position = nodeToIndex[element];
        
    // Recursive calls
    // Left sub-tree is build first
    root -> left = solve(in, pre, index, inorderStart, position - 1, n, nodeToIndex);
    root -> right = solve(in, pre, index, position + 1, inorderEnd, n, nodeToIndex);
        
    return root;
}
    
Node* buildTree(int in[],int pre[], int n) {
    int preOrderIndex = 0;
        
    map<int, int> nodeToIndex;
    // Create nodes to index mapping
    createMapping(in, nodeToIndex, n);
        
    Node* ans = solve(in, pre, preOrderIndex, 0, n - 1, n, nodeToIndex);
        
    return ans;
}