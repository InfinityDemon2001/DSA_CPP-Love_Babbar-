//REVERSING A LINKED LIST
LinkedListNode<int>* reverseLinkedList(LinkedListNode<int>* head) 
{
    if(head == NULL || head -> next == NULL) {
        return head;
    }

    LinkedListNode<int>* prev = NULL;
    LinkedListNode<int>* curr = head;
    LinkedListNode<int>* forward = NULL;

    while(curr != NULL) {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

//FINDING MIDDLE NODE OF THE LINKED LIST
Node* getMiddle(Node* head) {

    if(head == NULL || head -> next == NULL) {
        return head;
    }
    
    //2 nodes
    if(head -> next -> next == NULL) {
        return head -> next;
    }

    Node* slow = head;
    Node* fast = head -> next;

    while(fast != NULL) {
        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
        }
        slow = slow -> next;
    }
    return slow;
}

Node *findMiddle(Node *head) {
    return getMiddle(head);
}