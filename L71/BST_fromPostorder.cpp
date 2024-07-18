#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *left, *right;
};

Node* solve(int post[], int mini, int maxi, int &i) {
    if(i < 0) {
        return NULL;
    }
    if(post[i] < mini || post[i] > maxi) {
        return NULL;
    }
    
    Node* root = new Node(post[i --]);
    
    root -> right = solve(post, root -> data, maxi, i);
    root -> left = solve(post, mini, root -> data, i);
    
    return root;
}

Node* constructTree(int post[], int size) {
    int i = size - 1, mini = INT_MIN, maxi = INT_MAX;
    
    return solve(post, mini, maxi, i);
}