bool checksize(Node* head, int k) {
    int cnt = 0;
    Node* temp = head;

    while(temp != NULL && cnt < k) {
        temp = temp -> next;
        cnt ++;
    }

    if(cnt >= k) {
        return true;
    }

    return false;
}

Node* kReverse(Node* head, int k) {
    // basecase
    if(head == NULL) {
        return head;
    }

    int count = 0;
    // if it has efficint size
    if(checksize(head, k)){
        Node* pre=NULL;
        Node* cur=head;
        Node* forward =NULL;

        while(cur!=NULL && count<k){
            forward=cur->next;
            cur->next=pre;
            pre=cur;
            cur=forward;
            count++;
        }

        if(forward!=NULL){
            head->next=kReverse(forward,k);
        }
        return pre;
    }

//  ifsize is less than k
    else{
        return head;
    }
}