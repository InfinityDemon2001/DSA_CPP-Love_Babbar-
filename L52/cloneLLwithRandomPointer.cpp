#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *arb;

    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};

void insertAtTail(Node* &head, Node* &tail, int d) {
    Node* newNode = new Node(d);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    else {
        tail -> next = newNode;
        tail = newNode;
    }
}

//Approach 1
Node *copyList(Node *head) {
    //Step 1 -> Create a clone list
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;
        
    Node* temp = head;
        
    while(temp != NULL) {
        insertAtTail(cloneHead, cloneTail, temp -> data);
        temp = temp -> next;
    }
        
    //Step 2 -> Create a map
    unordered_map<Node*, Node*> oldToNewNode;
        
    Node* originalNode = head;
    Node* cloneNode = cloneHead;
        
    while(originalNode != NULL && cloneNode != NULL) {
        oldToNewNode[originalNode] = cloneNode;
        originalNode = originalNode -> next;
        cloneNode = cloneNode -> next;
    }
        
    originalNode = head;
    cloneNode = cloneHead;
        
    while(originalNode != NULL) {
        cloneNode -> arb = oldToNewNode[originalNode -> arb];
        originalNode = originalNode -> next;
        cloneNode = cloneNode -> next;
    }
    return cloneHead;
}

//Approach 2
Node *copyList(Node *head) {
    //Step 1 -> Create a clone list
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;
        
    Node* temp = head;
        
    while(temp != NULL) {
        insertAtTail(cloneHead, cloneTail, temp -> data);
        temp = temp -> next;
    }
        
    //Step 2 -> Add clone nodes in between original list
    Node* originalNode = head;
    Node* cloneNode = cloneHead;
        
    while(originalNode != NULL && cloneNode != NULL) {
        Node* next = originalNode -> next;
        originalNode -> next = cloneNode;
        originalNode = next;
            
        next = cloneNode -> next;
        cloneNode -> next = originalNode;
        cloneNode = next;
    }
        
    //Step 3 -> Copy random pointer
    temp = head;
        
    while(temp != NULL) {
        if(temp -> next != NULL) {
            temp -> next -> arb = temp -> arb ? temp -> arb -> next : temp -> arb;
        }
        temp = temp -> next -> next;
    }
        
    //Step 4 -> Revert changes done in Step 2
    originalNode = head;
    cloneNode = cloneHead;
        
    while(originalNode != NULL && cloneNode != NULL) {
        originalNode -> next =  cloneNode -> next;
        originalNode = originalNode -> next;
            
        if(originalNode != NULL) {
            cloneNode -> next = originalNode -> next;
        }
        cloneNode = cloneNode -> next;
    }

    //Step 5 -> Return ans
    return cloneHead;
}
