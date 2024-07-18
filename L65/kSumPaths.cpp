#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void solve(Node* root, int k, int &count, vector<int> path) {
    // Base case
    if(root == NULL) {
        return;
    }
        
    path.push_back(root -> data);
        
    // Left
    solve(root -> left, k, count, path);
    // Right
    solve(root -> right, k, count, path);
        
    // CHeck for k sum paths
    int size = path.size();
    int sum = 0;
        
    for(int i = size - 1; i >= 0; i --) {
        sum += path[i];
            
        if(sum == k) {
            count ++;
        }
    }
        
    path.pop_back();
}
    
int sumK(Node *root,int k) {
    vector<int> path;
    int count = 0;
        
    solve(root, k, count, path);
        
    return count;
}