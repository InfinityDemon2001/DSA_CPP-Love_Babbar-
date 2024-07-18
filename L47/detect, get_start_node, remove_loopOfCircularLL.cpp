#include <iostream>
#include <map>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
};


//Detecting loop in Circular Linked List
//Approach 1
bool detectLoop(Node* head) {
    if(head == NULL) {
        return false;
    }

    map<Node*, bool> visited;

    Node* temp = head;

    while(temp != NULL) {
        //cycle is present
        if(visited[temp] == true) {
            cout << "Loop present on " << temp -> data << endl;
            return true;
        }
        visited[temp] = true;
        temp = temp -> next;
    }
    return false;
}

//Approach 2
Node* floydDetectLoop(Node* head) {
    if(head == NULL) {
        return NULL;
    }

    Node* fast = head;
    Node* slow = head;

    while(slow != NULL && fast != NULL) {
        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
        }
        slow = slow -> next;

        if(slow == fast) {
            return slow;
        }
    }
    return NULL;
}

//Getting start node of loop in Linked List
Node* getStartingNode(Node* head) {
    if(head == NULL) {
        return NULL;
    }

    Node* intersection = floydDetectLoop(head);
    Node* slow = head;

    if(intersection == NULL) {
        return NULL;
    }

    while (slow != intersection) {
        intersection = intersection -> next;
        slow = slow -> next;
    }

    return slow;
}

//Remove Loop from a Linked List
Node* removeLoop(Node* head) {
    if(head == NULL) {
        return NULL;
    }

    Node* startOfLoop = getStartingNode(head);
    Node* temp = startOfLoop;

    if(startOfLoop == NULL) {
        return head;
    }

    while(temp -> next != startOfLoop) {
        temp = temp -> next;
    }

    temp -> next = NULL;
    return head;
}