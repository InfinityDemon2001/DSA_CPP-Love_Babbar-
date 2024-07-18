#include <bits/stdc++.h>
using namespace std;

class compare {
    public:
    bool operator() (Node* a, Node* b) {
        return a -> data > b -> data;
    }
};

Node* mergeKLists(vector<Node*> &lists) {
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    int k = lists.size();

    for(int i = 0; i < k; i ++) {
        if(lists[i] != NULL) {
            minHeap.push(lists[i]);
        }
    }

    Node* head = NULL;
    Node* tail = NULL;

    while(minHeap.size() > 0) {
        Node* top = minHeap.top();
        minHeap.pop();

        if(top -> next != NULL) {
            minHeap.push(top -> next);
        }

        if(head == NULL) {
            // LL empty
            head = top;
            tail = top;
        }
        else {
            // Insert at end
            tail -> next = top;
            tail = top;
        }
    }

    return head;
}