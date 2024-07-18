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

// Create mapping
// Return target node
Node* createParentMapping(Node* root, int target, map<Node*, Node*> &nodeToParent) {
    Node* res = NULL;
    
    queue<Node*> q;
    q.push(root);
    nodeToParent[root] = NULL;
    
    while(!q.empty()) {
        Node* front = q.front();
        q.pop();
        
        if(front -> data == target) {
            res = front;
        }
        if(front -> left) {
            nodeToParent[front -> left] = front;
            q.push(front -> left);
        }
        if(front -> right) {
            nodeToParent[front -> right] = front;
            q.push(front -> right);
        }
    }
    
    return res;
}
    
int burnTree(Node* root, map<Node*, Node*> &nodeToParent) {
    map<Node*, bool> visited;
    int time = 0;
    queue<Node*> q;
    
    q.push(root);
    visited[root] = true;
    
    while(!q.empty()) {
        bool flag = 0;
        int size = q.size();
        
        for(int i = 0; i < size; i ++) {
            // Process neighbouring nodes
            Node* front = q.front();
            q.pop();
            
            if(front -> left && !visited[front -> left]) {
                q.push(front -> left);
                visited[front -> left] = 1;
                flag = 1;
            }
            if(front -> right && !visited[front -> right]) {
                q.push(front -> right);
                visited[front -> right] = 1;
                flag = 1;
            }
            if(nodeToParent[front] && !visited[nodeToParent[front]]) {
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = 1;
                flag = 1;
            }
        }
        
        if(flag == 1) {
            time ++;
        }
    }
    
    return time;
}

int minTime(Node* root, int target) 
{
    map<Node*, Node*> nodeToParent;
    Node* targetNode = createParentMapping(root, target, nodeToParent);
    
    int time = burnTree(targetNode, nodeToParent);
    
    return time;
}