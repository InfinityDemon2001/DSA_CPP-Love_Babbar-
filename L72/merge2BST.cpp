#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};


// Approach 1
void inorder(TreeNode* root, vector<int> &in) {
    if(root == NULL) {
        return;
    }

    inorder(root -> left, in);
    in.push_back(root -> data);
    inorder(root -> right, in);
}

TreeNode* inorderToBST(int s, int e, vector<int> &in) {
    if(s > e) {
        return NULL; 
    }

    int mid = (s + e) / 2;

    TreeNode* root = new TreeNode(in[mid]);

    root -> left = inorderToBST(s, mid - 1, in);
    root -> right = inorderToBST(mid + 1, e, in);

    return root;
}

vector<int> mergeArrays(vector<int> &bst1, vector<int> &bst2) {
    vector<int> ans(bst1.size() + bst2.size());

    int i = 0, j = 0, k = 0;

    while(i < bst1.size() && j < bst2.size()) {
        if(bst1[i] < bst2[j]) {
            ans[k ++] = bst1[i];
            i ++;
        }
        else {
            ans[k ++] = bst2[j];
            j ++;
        }
    }

    while(i < bst1.size()) {
        ans[k ++] = bst1[i];
        i ++;
    }
    while(j < bst2.size()) {
        ans[k ++] = bst2[j];
        j ++;
    }

    return ans;
}

vector<int> mergeBST(TreeNode* root1, TreeNode* root2) {
    // Store inorder
    vector<int> bst1, bst2;
    inorder(root1, bst1);
    inorder(root2, bst2);

    vector<int> mergedArray = mergeArrays(bst1, bst2);

    int s = 0, e = mergedArray.size() - 1;

    return inorderToBST(s, e, mergedArray);
}

// Approach 2
void convertIntoSortedDLL(TreeNode* root, TreeNode* &head) {
    // Base case
    if(root == NULL) {
        return NULL;
    }

    convertIntoSortedDLL(root -> right, head);

    root -> right = head;

    if(head != NULL) {
        head -> left = root;
    }

    head = root;

    convertIntoSortedDLL(root -> left, head);
}

TreeNode* mergeLinkedList(TreeNode* head1, TreeNode* head2) {
    TreeNode* head = NULL;
    TreeNode* tail = NULL;

    while(head1 != NULL && head2 != NULL) {
        if(head1 -> data < head2 -> data) {
            if(head == NULL) {
                head = head1;
                tail = head1;
                head1 = head1 -> right;
            }
            else {
                tail -> right = head1;
                head1 -> left = tail;
                tail = head1;
                head1 = head1 -> right;
            }
        }
        else {
            if(head == NULL) {
                head = head2;
                tail = head2;
                head2 = head2 -> right;
            }
            else {
                tail -> right = head2;
                head2 -> left = tail;
                tail = head2;
                head1 = head2 -> right;
            }
        }
    }

    while(head1 != NULL) {
        tail -> right = head1;
        head1 -> left = tail;
        tail = head1;
        head1 = head1 -> right;
    }
    while(head2 != NULL) {
        tail -> right = head2;
        head2 -> left = tail;
        tail = head2;
        head1 = head2 -> right;
    }

    return head;
}

int countNodes(TreeNode* head) {
    int cnt = 0;

    TreeNode* temp = head;

    while(temp != NULL) {
        cnt ++;
        temp = temp -> right;
    }

    return cnt;
}

TreeNode* sortedLLToBST(TreeNode* &head, int n) {
    // Base case
    if(n <= 0 || head == NULL) {
        return NULL;
    }

    TreeNode* left = sortedLLToBST(head, n / 2);

    TreeNode* root = head;

    root -> left = left;

    head = head -> next;

    root -> right = sortedLLToBST(head, n - n / 2 - 1);

    return root;
}

TreeNode* mergeBST2(TreeNode* root1, TreeNode* root2) {
    // Convert BST into sorted DLL in place
    TreeNode* head1 = NULL;
    convertIntoSortedDLL(root1, root2);
    head1 -> left = NULL;

    TreeNode* head2 = NULL;
    convertIntoSortedDLL(root2, head2);
    head2 -> left = NULL;

    // Merge sorted LL
    TreeNode* head = mergeLinkedList(head1, head2);

    // Convert sorted LL into BST
    return sortedLLToBST(head, countNodes(head));
}