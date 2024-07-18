#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    deque<long long int> dq;
    vector<long long int> ans;
    
    // Process first window of k size
    for(int i = 0; i < K; i ++) {
        if(A[i] < 0) {
            dq.push_back(i);
        }
    }
    
    // Store answer of first k size window
    if(dq.size() > 0) {
        ans.push_back(A[dq.front()]);
    }
    else {
        ans.push_back(0);
    }
    
    // Process for remaining windows
    for(int i = K; i < N; i ++) {
        // Removal
        if(!dq.empty() && i - dq.front() >= K) {
            dq.pop_front();
        }
        
        // Addition
        if(A[i] < 0) {
            dq.push_back(i);
        }
        
        // Store answer
        if(dq.size() > 0) {
            ans.push_back(A[dq.front()]);
        }
        else {
            ans.push_back(0);
        }
    }
    return ans;
}