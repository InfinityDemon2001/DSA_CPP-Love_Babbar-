#include <bits/stdc++.h>
using namespace std;

int main() {
    //Create a queue
    queue<int> q;

    q.push(11);
    q.push(13);
    q.push(15);

    cout << "Size of queue:" << q.size() << endl;

    q.pop();
    q.pop();
    q.pop();

    cout << "Size of queue:" << q.size() << endl;

    if(q.empty()) {
        cout << "Queue is empty." << endl;
    }
    else {
        cout << "Queue is not empty" << endl;
    }

    return 0;
}