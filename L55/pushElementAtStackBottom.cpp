#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>

void solve(stack<int>& myStack, int x) {
    //Base case
    if(myStack.size() == 0) {
        myStack.push(x);
        return;
    }

    int temp =  myStack.top();
    myStack.pop();

    //Recursive call
    solve(myStack, x);

    myStack.push(temp);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    solve(myStack, x);

    return myStack;
}