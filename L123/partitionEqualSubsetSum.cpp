#include <bits/stdc++.h>

// Method 1: Recursion
bool solve(int index, int arr[], int N, int target) {
    // Base case
    if(index >= N) {
        return 0;
    }
    if(target < 0) {
        return 0;
    }
    if(target == 0) {
        return 1;
    }
        
    bool include = solve(index + 1, arr, N, target - arr[index]);
    bool exclude = solve(index + 1, arr, N, target - 0);
        
    return include || exclude;
}
    
bool equalPartition(int N, int arr[]) {
    int total = 0;
        
    for(int i = 0; i < N; i ++) {
        total += arr[i];
    }
        
    if(total & 1) {
        return 0;
    }
        
    int target = total / 2;
        
    return solve(0, arr, N, target);
}

// Method 2: Memoization
bool solve(int index, int arr[], int N, int target, vector<vector<int>> &dp) {
    // Base case
    if(index >= N) {
        return 0;
    }
    if(target < 0) {
        return 0;
    }
    if(target == 0) {
        return 1;
    }
    if(dp[index][target] != -1) {
        return dp[index][target];
    }
        
    bool include = solve(index + 1, arr, N, target - arr[index], dp);
    bool exclude = solve(index + 1, arr, N, target, dp);
        
    dp[index][target] = include || exclude;
        
    return dp[index][target];
}
    
int equalPartition(int N, int arr[]) {
    int total = 0;
        
    for(int i = 0; i < N; i ++) {
        total += arr[i];
    }
        
    if(total & 1) {
        return 0;
    }
        
    int target = total / 2;
        
    vector<vector<int>> dp(N + 1, vector<int> (target + 1, -1));
        
    return solve(0, arr, N, target, dp);
}

// Method 3: Tabulation
bool solve(int arr[], int N, int total) {
    vector<vector<int>> dp(N + 1, vector<int> ((total / 2) + 1, 0));
        
    for(int i = 0; i <= N; i ++) {
        dp[i][0] = 1;
    }
        
    for(int index = N - 1; index >= 0; index --) {
        for(int target = 0; target <= total / 2; target ++) {
            bool include = 0;
                
            if(target - arr[index] >= 0) {
                include = dp[index + 1][target - arr[index]];
            }
                
            bool exclude = dp[index + 1][target];
                
            dp[index][target] = include || exclude;
        }
    }
        
    return dp[0][total / 2];
}
    
int equalPartition(int N, int arr[]) {
    int total = 0;
        
    for(int i = 0; i < N; i ++) {
        total += arr[i];
    }
        
    if(total & 1) {
        return 0;
    }
        
    return solve(arr, N, total);
}

// Method 4: Space Optimization
bool solve(int arr[], int N, int total) {
    vector<int> curr((total / 2) + 1, 0);
    vector<int> next((total / 2) + 1, 0);
        
    curr[0] = 1;
    next[0] = 1;
        
    for(int index = N - 1; index >= 0; index --) {
        for(int target = 0; target <= total / 2; target ++) {
            bool include = 0;
                
            if(target - arr[index] >= 0) {
                include = next[target - arr[index]];
            }
                
            bool exclude = next[target];
                
            curr[target] = include || exclude;
        }
            
        next = curr;
    }
        
    return next[total / 2];
}
    
int equalPartition(int N, int arr[]) {
    int total = 0;
        
    for(int i = 0; i < N; i ++) {
        total += arr[i];
    }
        
    if(total & 1) {
        return 0;
    }
        
    return solve(arr, N, total);
}