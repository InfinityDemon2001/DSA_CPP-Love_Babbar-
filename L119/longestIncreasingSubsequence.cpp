#include <bits/stdc++.h>

// Method 1: Recursion
int solve(int n, int a[], int curr, int prev) {
    // Base case
    if(curr == n) {
        return 0;
    }
        
    // Include
    int take = 0;
        
    if(prev == -1 || a[curr] > a[prev]) {
        take = 1 + solve(n, a, curr + 1, curr);
    }
        
    // Exclude
    int notTake = 0 + solve(n, a, curr + 1, prev);
        
    return max(take, notTake);
}
    
int longestSubsequence(int n, int a[]) {
    return solve(n, a, 0, -1);
}

// Method 2: Memoization
int solve(int n, int a[], int curr, int prev, vector<vector<int>> &dp) {
    // Base case
    if(curr == n) {
        return 0;
    }
    if(dp[curr][prev + 1] != -1) {
        return dp[curr][prev + 1];
    }
        
    // Include
    int take = 0;
        
    if(prev == -1 || a[curr] > a[prev]) {
        take = 1 + solve(n, a, curr + 1, curr, dp);
    }
        
    // Exclude
    int notTake = 0 + solve(n, a, curr + 1, prev, dp);
        
    dp[curr][prev + 1] = max(take, notTake);
        
    return dp[curr][prev + 1];
}
    
int longestSubsequence(int n, int a[]) {
    vector<vector<int>> dp(n, vector<int> (n + 1, -1));
        
    return solve(n, a, 0, -1, dp);
}

// Method 3: Tabulation
int solve(int n, int a[]) {
    vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
        
    for(int curr = n - 1; curr >= 0; curr --) {
        for(int prev = curr - 1; prev >= -1; prev --) {
            // Include
            int take = 0;
        
            if(prev == -1 || a[curr] > a[prev]) {
                take = 1 + dp[curr + 1][curr + 1];
            }
                
            // Exclude
            int notTake = 0 + dp[curr + 1][prev + 1];
                
            dp[curr][prev + 1] = max(take, notTake);
        }
    }
        
    return dp[0][0];
}
    
int longestSubsequence(int n, int a[]) {
    return solve(n, a);
}

// Method 4: Space Optimization
int solve(int n, int a[]) {
    vector<int> currRow(n + 1, 0);
    vector<int> nextRow(n + 1, 0);
        
    for(int curr = n - 1; curr >= 0; curr --) {
        for(int prev = curr - 1; prev >= -1; prev --) {
            // Include
            int take = 0;
        
            if(prev == -1 || a[curr] > a[prev]) {
                take = 1 + nextRow[curr + 1];
            }
                
            // Exclude
            int notTake = 0 + nextRow[prev + 1];
                
            currRow[prev + 1] = max(take, notTake);
        }
        nextRow = currRow;
    }
        
    return nextRow[0];
}
    
int longestSubsequence(int n, int a[]) {
    return solve(n, a);
}

// Method 5: Optimization with binary search
int solve(int n, int a[]) {
    if(n == 0) {
        return 0;
    }
        
    vector<int> ans;
        
    ans.push_back(a[0]);
        
    for(int i = 1; i < n; i ++) {
        if(a[i] > ans.back()) {
            ans.push_back(a[i]);
        }
        else {
            int index = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
            ans[index] = a[i];
        }
    }
        
    return ans.size();
}
    
int longestSubsequence(int n, int a[]) {
    return solve(n, a);
}