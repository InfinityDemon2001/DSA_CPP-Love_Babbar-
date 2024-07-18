#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
	int data;
	Node *next;
    Node *child;
	Node() : data(0), next(nullptr), child(nullptr){};
 	Node(int x) : data(x), next(nullptr), child(nullptr) {}
 	Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
};

Node* merge(Node* a, Node* b) {
    Node *temp = new Node(0);
    Node *res = temp; 
    
    while(a != NULL && b != NULL) {
        if(a -> data < b -> data) {
            temp -> child = a; 
            temp = temp -> child; 
            a = a -> child; 
        }
        else {
            temp -> child = b;
            temp = temp -> child; 
            b = b -> child; 
        }
    }
    
    if(a) temp -> child = a; 
    else temp -> child = b; 
    
    return res -> child; 
}

Node* flattenLinkedList(Node* head) 
{
   
        if (head == NULL || head -> next == NULL) 
            return head; 

        //Recursion for list on right 
        head -> next = flattenLinkedList(head -> next); 
  
        //Now merge 
        head = merge(head, head -> next); 
  
        //Return the head
        return head; 
}