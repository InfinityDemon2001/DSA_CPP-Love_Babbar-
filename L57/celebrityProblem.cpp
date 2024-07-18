#include <bits/stdc++.h>
using namespace std;

bool knows(vector<vector<int> >& M,int a, int b, int n) {
    if(M[a][b] == 1) {
        return true;
    }
        
    return false;
}

int celebrity(vector<vector<int> >& M, int n) {
    stack<int> s;
        
    //Step 1 -> Push all elements into stack
    for(int i = 0; i < n; i ++) {
        s.push(i);
    }
        
    //Step 2 -> Get 2 elements and compare them
    while(s.size() > 1) {
        int a = s.top();
        s.pop();
            
        int b = s.top();
        s.pop();
            
        if(knows(M, a, b, n)) {
            s.push(b);
        }
        else {
            s.push(a);
        }
    }
        
    int ans = s.top();
        
    //Step 3 -> Single element in stack is candidate, therefore verify it
    int zeroCount = 0;
    for(int i = 0; i < n; i ++) {
        if(M[ans][i] == 0) {
            zeroCount ++;
        }
    }
    if(zeroCount != n) {
        return -1;
    }
        
    int oneCount = 0;
    for(int i = 0; i < n; i ++) {
        if(M[i][ans] == 1) {
            oneCount ++;
        }
    }
    if(oneCount != n - 1) {
        return -1;
    }
        
    return ans;
}