#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
};

//Approach 1
Node* sortList(Node *head){
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    Node* temp = head;

    while(temp != NULL) {
        if(temp -> data == 0) {
            zeroCount ++;
        }
        else if(temp -> data == 1) {
            oneCount ++;
        }
        else if(temp -> data == 2) {
            twoCount ++;
        }

        temp = temp -> next;
    }

    temp = head;

    while(temp != NULL) {
        if(zeroCount != 0) {
            temp -> data = 0;
            zeroCount --;
        }
        else if(oneCount != 0) {
            temp -> data = 1;
            oneCount --;
        }
        else if(twoCount != 0) {
            temp -> data = 2;
            twoCount --;
        }

        temp = temp -> next;
    }

    return head;
}

//Approach 2
void insertAtTail(Node* &tail, Node* curr) {
    tail -> next = curr;
    tail = curr;
}

Node* sortList(Node *head){
    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneTail = oneHead;
    Node* twoTail = twoHead;

    Node* curr = head;
    
    //create 3 separate lists of 0s, 1s & 2s
    while(curr != NULL) {
        int val = curr -> data;

        if(val == 0) {
            insertAtTail(zeroTail, curr);
        }
        else if(val == 1) {
            insertAtTail(oneTail, curr);
        }
        else if(val == 2) {
            insertAtTail(twoTail, curr);
        }

        curr = curr -> next;
    }

    //merge 3 sublists
    if(oneHead -> next != NULL) {
        //1s list is not empty
        zeroTail -> next = oneHead -> next;
    }
    else {
        //1s list is empty
        zeroTail ->next = twoHead -> next;
    }
    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL;

    //setup head
    head = zeroHead -> next;

    //delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}