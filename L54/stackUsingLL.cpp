#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class myStack {
    Node* head;
    int stackSize;

    public:
    myStack() {
        head = NULL;
        stackSize = 0;
    }

    void push(int g) {
        Node* temp = new Node();
        temp -> data = g;
        temp -> next = head;
        head = temp;

        cout << "Element " << g << " pushed into the stack." << endl;

        stackSize ++;
    }

    void pop() {
        if(head == NULL) {
            cout << "Stack is empty. Cannot POP an element." << endl;
            return;
        }

        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;

        cout << "Element popped." << endl;
    }

    int top() {
        if(head == NULL) {
            cout << "Stack is empty, no top element present." << endl;
            return -1;
        }
        
        cout << "Top element is " << head -> data << endl;
        return head -> data;
    }

    int size() {
        return stackSize;
    }

    int empty() {
        if(head == NULL) {
            cout << "Stack is empty." << endl;
            return 1;
        }

        cout << "Stack is not empty." << endl;
        return 0;
    }
};

int main() {
    myStack s1;

    s1.empty();
    s1.push(7);
    s1.push(9);

    s1.pop();

    s1.push(10);

    s1.top();

    s1.empty();
}