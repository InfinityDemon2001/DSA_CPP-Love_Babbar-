#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
};

Node *removeDuplicates(Node *head) {
    if(head == NULL || head -> next == NULL) {
        return head;
    }

    unordered_map<int, bool> visited;
    Node* prev = head;
    Node* curr = head;


    while(curr != NULL) {
        if(visited[curr -> data] == true) {
            prev -> next = curr -> next;
            curr = curr -> next;
        }
        else {
            visited[curr -> data] = true;
            prev = curr;
            curr = curr -> next;
        }
    }
    return head;
}