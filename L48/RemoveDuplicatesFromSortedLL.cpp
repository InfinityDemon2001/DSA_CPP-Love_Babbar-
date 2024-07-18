#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
};

Node * removeDuplicates(Node *head)
{
    //empty list
    if(head == NULL) {
        return NULL;
    }

    Node* curr = head;

    while(curr != NULL) {
        if(curr -> next != NULL && curr -> data == curr -> next -> data) {
            Node* next_next = curr -> next -> next;
            Node* nodeToDelete = curr -> next;
            delete(nodeToDelete);
            curr -> next = next_next;
        }
        //not equal
        else {
            curr = curr -> next;
        }
    }

    return head;
}