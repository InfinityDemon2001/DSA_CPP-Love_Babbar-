#include <bits/stdc++.h>
using namespace std;

class BinaryTreeNode {
       public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

BinaryTreeNode<int>* solve(vector<int> &preorder, int mini, int maxi, int &i) {
    if(i >= preorder.size()) {
        return NULL;
    }
    if(preorder[i] < mini || preorder[i] > maxi) {
        return NULL;
    }

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[i ++]);

    root -> left = solve(preorder, mini, root -> data, i);
    root -> right = solve(preorder, root -> data, maxi, i);

    return root;
}

BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    int i = 0, mini = INT_MIN, maxi = INT_MAX;

    return solve(preorder, mini, maxi, i);
}