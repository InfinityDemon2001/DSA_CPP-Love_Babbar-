#include<bits/stdc++.h>
using namespace std;

// Method 1: Top Down Approach -> Recursion + Memoization
int fib(int n, vector<int> &dp) {
    // Base case
    if(n <= 1) {
        return n;
    }

    // Step 3
    if(dp[n] != -1) {
        return dp[n];
    }

    // Step 2
    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    
    // Step 1
    vector<int> dp(n + 1, -1);
    
    cout << fib(n, dp) << endl;
    
    return 0;
}

// Method 2: Bottom Up Approach
int fibo(int n) {
    if( n <= 1) {
        return n;
    }

    int prev1 = 1;
    int prev2 = 0;

    for(int i = 2; i <= n; i ++) {
        int curr = prev1 + prev2;

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}