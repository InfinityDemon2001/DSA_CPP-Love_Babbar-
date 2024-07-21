#include <bits/stdc++.h>

// Method 1: Recursion
long long solve(int dice, int faces, int target) {
    // Base case
    if(target < 0) {
        return 0;
    }
    if(dice == 0 && target != 0) {
        return 0;
    }
    if(dice != 0 && target == 0) {
        return 0;
    }
    if(dice == 0 && target == 0) {
        return 1;
    }
        
    long long ans = 0;
        
    for(int i = 1; i <= faces; i ++) {
        ans = ans + solve(dice - 1, faces, target - i);
    }
        
    return ans;
}
    
long long noOfWays(int M , int N , int X) {
    return solve(N, M, X);
}

// Method 2: Memoization
long long solve(int dice, int faces, int target, vector<vector<long long>> &dp) {
    // Base case
    if(target < 0) {
        return 0;
    }
    if(dice == 0 && target != 0) {
        return 0;
    }
    if(dice != 0 && target == 0) {
        return 0;
    }
    if(dice == 0 && target == 0) {
        return 1;
    }
    if(dp[dice][target] != -1) {
        return dp[dice][target];
    }
        
    long long ans = 0;
        
    for(int i = 1; i <= faces; i ++) {
        ans = ans + solve(dice - 1, faces, target - i, dp);
    }
        
    return dp[dice][target] = ans;
}
    
long long noOfWays(int M , int N , int X) {
    vector<vector<long long>> dp(N + 1, vector<long long> (X + 1, -1));
        
    return solve(N, M, X, dp);
}

// Method 3: Tabulation
long long solve(int d, int f, int t) {
    vector<vector<long long>> dp(d + 1, vector<long long> (t + 1, 0));
        
    dp[0][0] = 1;
        
    for(int dice = 1; dice <= d; dice ++) {
        for(int target = 1; target <= t; target ++) {
            long long ans = 0;
                
            for(int i = 1; i <= f; i ++) {
                if(target - i >= 0) {
                    ans = ans + dp[dice - 1][target - i];
                }
            }
                
            dp[dice][target] = ans;
        }
    }
        
    return dp[d][t];
}
    
long long noOfWays(int M , int N , int X) {
    return solve(N, M, X);
}

// Method 4: Space Optimization
long long solve(int d, int f, int t) {
    vector<long long> prev(t + 1, 0);
    vector<long long> curr(t + 1, 0);
        
    prev[0] = 1;
        
    for(int dice = 1; dice <= d; dice ++) {
        for(int target = 1; target <= t; target ++) {
            long long ans = 0;
                
            for(int i = 1; i <= f; i ++) {
                if(target - i >= 0) {
                    ans = ans + prev[target - i];
                }
            }
                
            curr[target] = ans;
        }
            
        prev = curr;
    }
        
    return prev[t];
}
    
long long noOfWays(int M , int N , int X) {
    return solve(N, M, X);
}