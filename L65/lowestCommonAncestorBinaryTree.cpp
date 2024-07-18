#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

Node* lca(Node* root ,int n1 ,int n2 ) {
    // Base case
    if(root == NULL) {
        return NULL;
    }
       
    if(root -> data == n1 || root -> data == n2) {
        return root;
    }
       
    Node* leftAns = lca(root -> left, n1, n2);
    Node* rightAns = lca(root -> right, n1, n2);
       
    if(leftAns != NULL && rightAns != NULL) {
       return root;
    }
    else if(leftAns != NULL && rightAns == NULL) {
        return leftAns;
    }
    else if(rightAns != NULL && leftAns == NULL) {
        return rightAns;
    }
    else {
        return NULL;
    }
}