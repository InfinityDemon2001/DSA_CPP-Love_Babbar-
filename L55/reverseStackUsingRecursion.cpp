#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &stack, int num) {
    //Base case
    if(stack.size() == 0) {
        stack.push(num);
        return;
    }

    int temp =  stack.top();
    stack.pop();

    //Recursive call
    insertAtBottom(stack, num);

    stack.push(temp);
}

void reverseStack(stack<int> &stack) {
    //Base case
    if(stack.empty()) {
        return;
    }

    int num = stack.top();
    stack.pop();

    //Rceursive call
    reverseStack(stack);

    insertAtBottom(stack, num);
}