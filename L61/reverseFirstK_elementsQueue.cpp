#include <bits/stdc++.h>
using namespace std;

queue<int> modifyQueue(queue<int> q, int k) {
    // Step 1 -> Pop first k elements from queue and push into stack
    stack<int> s;
        
    for(int i = 0; i < k; i ++) {
        int element = q.front();
        q.pop();
        s.push(element);
    }
        
    // Step 2 -> Fetch from stack and push into queue
    while(!s.empty()) {
        int element = s.top();
        s.pop();
        q.push(element);
    }
        
    // Step 3 -> Fetch first (n - k) elements of the queue and push to the end
    int n = q.size();
        
    for(int i = 0; i < n - k; i ++) {
        int val = q.front();
        q.pop();
        q.push(val);
    }
        
    return q;
}