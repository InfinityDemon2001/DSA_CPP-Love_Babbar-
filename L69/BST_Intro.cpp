#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) {
            // Current level complete
            cout << endl;
            if(!q.empty()) {
                // Queue still has some child node left
                q.push(NULL);
            }
        }
        else {
            cout << temp -> data << " ";
            if(temp -> left) {
                q.push(temp -> left);
            }
            if(temp -> right) {
                q.push(temp -> right);
            }
        }
    }
}

void preorder(Node* root) {
    // Base case
    if(root == NULL) {
        return;
    }

    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);
}

void inorder(Node* root) {
    // Base case
    if(root == NULL) {
        return;
    }

    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}

void postorder(Node* root) {
    // Base case
    if(root == NULL) {
        return;
    }

    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << " ";
}

Node* insertIntoBST(Node* &root, int d) {
    // Base case
    if(root == NULL) {
        root = new Node(d);
        return root;
    }

    if(d > root -> data) {
        // Insert at right part
        root -> right = insertIntoBST(root -> right, d);
    }
    else {
        // Insert at left part
        root -> left = insertIntoBST(root -> left, d);
    }

    return root;
}

Node* minVal(Node* root) {
    Node* temp = root;

    while(temp -> left != NULL) {
        temp = temp -> left;
    }

    return temp;
}

Node* maxVal(Node* root) {
    Node* temp = root;

    while(temp -> right != NULL) {
        temp = temp -> right;
    }

    return temp;
}

void takeInput(Node* &root) {
    int data;
    cin >> data;

    while(data != -1) {
        insertIntoBST(root, data);
        cin >> data;
    }
}

Node* deleteFromBST(Node* root, int val) {
    // Base case
    if(root == NULL) {
        return root;
    }

    if(root -> data == val) {
        // 0 child
        if(root -> left == NULL && root -> right == NULL) {
            delete root;
            return NULL;
        }

        // 1 child
        // Left child
        if(root -> left != NULL && root -> right == NULL) {
            Node* temp = root -> left;
            delete root;
            return temp;
        }
        // Right child
        if(root -> left == NULL && root -> right != NULL) {
            Node* temp = root -> right;
            delete root;
            return temp;
        }

        // 2 child
        if(root -> left != NULL && root -> right != NULL) {
            int mini = minVal(root -> right) -> data;
            root -> data = mini;
            root -> right = deleteFromBST(root -> right, mini);
            return root;
        }
    }
    else if(root -> data > val) {
        // Left part
        root -> left = deleteFromBST(root -> left, val);
        return root;
    }
    else {
        // Right part
        root -> right = deleteFromBST(root -> right, val);
        return root;
    }
}

int main() {
    Node* root = NULL;

    cout << "Enter data to create BST" << endl;

    takeInput(root);

    cout << "Printing the BST\n";
    levelOrderTraversal(root);

    cout << "\nPrinting Inorder\n";
    inorder(root);

    cout << "\nPrinting Preorder\n";
    preorder(root);

    cout << "\nPrinting Postorder\n";
    postorder(root);

    cout << "\nMinimun value is " << minVal(root) -> data << endl;
    cout << "Maximum value is " << maxVal(root) -> data << endl;

    root = deleteFromBST(root, 30);

    return 0;
}