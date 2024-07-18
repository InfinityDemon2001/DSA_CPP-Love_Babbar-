#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

vector<int> reverseLevelOrder(Node *root) {
    vector<int> ans;
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()) {
        Node* temp = q.front();
        ans.push_back(temp -> data);
        if(temp -> right) {
            q.push(temp -> right);
        }
        if(temp -> left) {
            q.push(temp -> left);
        }
        q.pop();
    }
    
    reverse(ans.begin(), ans.end());
    
    return ans;
}