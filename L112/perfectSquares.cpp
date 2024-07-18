#include <bits/stdc++.h>

// Method 1: Recursion
int MinSquares(int n) {
    if(n == 0) {
        return 0;
    }
    
    int ans = n;
    
    for(int i = 1; i * i <= n; i ++) {
        int temp = i * i;
        
        ans = min(ans, 1 + MinSquares(n - temp));
    }
    
    return ans;
}

// Method 2: Memoization
int solve(int n, vector<int> &dp) {
    if(n == 0) {
        return 0;
    }
    if(dp[n] != -1) {
        return dp[n];
    }
    
    int ans = n;
    
    for(int i = 1; i * i <= n; i ++) {
        int temp = i * i;
        
        ans = min(ans, 1 + solve(n - temp, dp));
    }
    
    dp[n] = ans;
    
    return dp[n];
}

int MinSquares(int n) {
    vector<int> dp(n + 1, -1);
    
    return solve(n, dp);
}

// Method 3: Tabulation
int solve(int n) {
    vector<int> dp(n + 1, INT_MAX);
    
    dp[0] = 0;
    
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j * j <= n; j ++) {
            int temp = j * j;

            if(i - temp >= 0) {
                dp[i] = min(dp[i], 1 + dp[i - temp]);
            }
        }
    }
    
    return dp[n];
}

int MinSquares(int n) {
    return solve(n);
}