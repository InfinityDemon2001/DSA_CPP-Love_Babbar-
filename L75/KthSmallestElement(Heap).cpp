#include <bits/stdc++.h>
using namespace std;

int kthSmallest(int arr[], int l, int r, int k) {
    priority_queue<int> pq;
    
    // Step 1:
    for(int i = l; i < k; i ++) {
        pq.push(arr[i]);
    }
    
    // Step 2:
    for(int i = k; i <= r; i ++) {
        if(pq.top() > arr[i]) {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    
    // Return top element
    return pq.top();
}