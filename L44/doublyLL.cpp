#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int d) {
        this -> data = d;
        this -> prev = NULL;
        this -> next = NULL;
    }

    Node() {
        int value = this -> data;
        //memory free
        if(this -> next != NULL) {
            delete next;
            this -> next = NULL;
        }
        cout << "memory is free for node with data " << value << endl;
    }
};


//traversing a linked list
void print(Node* &head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

//gives length of the Linked List
int getLength(Node* head) {
    Node* temp = head;
    int cnt = 0;

    while(temp != NULL) {
        cnt ++;
        temp = temp -> next;
    }

    return cnt;
}

void insertAtHead(Node* &head, Node* &tail, int d) {

    //empty list
    if(head == NULL) {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else {
        Node* temp = new Node(d);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
}

void insertAtTail(Node* &head, Node* &tail, int d) {
    if(tail == NULL) {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else {
        Node* temp = new Node(d);
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node* &head, Node* &tail, int position, int d) {

    //insert at Start
    if(position == 1) {
        insertAtHead(head, tail, d);
        return;
    }
    Node* temp = head;
    int cnt = 1;

    while(cnt < position - 1) {
        temp = temp -> next;
        cnt ++;
    }

    //inserting at last position
    if(temp -> next == NULL) {
        insertAtTail(head, tail, d);
        return;
    }

    //creating a node for d
    Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;
}

void deleteNode(int position, Node* &head) {

    //deleting first or start node
    if(position == 1) {
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }
    else {
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt ++;
        }

        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}

int main() {
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    print(head);
    cout << getLength(head) << endl;

    insertAtHead(head, tail, 11);
    print(head);

    insertAtHead(head, tail, 13);
    print(head);

    insertAtHead(head, tail, 8);
    print(head);

    insertAtTail(head, tail, 25);
    print(head);

    insertAtPosition(head, tail, 2, 100);
    print(head);

    insertAtPosition(head, tail, 1, 101);
    print(head);

    insertAtPosition(head, tail, 8, 102);
    print(head);

    deleteNode(1, head);
    print(head);

    deleteNode(6, head);
    print(head);

    deleteNode(1, head);
    print(head);

    return 0;
}