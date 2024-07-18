#include <bits/stdc++.h>
using namespace std;

int main() {

    //Creation of stack
    stack<int> s;

    //Push Operation
    s.push(2);
    s.push(3);

    //Pop Operation
    s.pop();

    cout << "Printing top element: " << s.top() << endl;

    if(s.empty()) {
        cout << "Stack is empty." << endl;
    }
    else {
        cout << "Stack is not empty." << endl;
    }

    cout << "Size of stack is " << s.size() << endl;

    return 0;
}