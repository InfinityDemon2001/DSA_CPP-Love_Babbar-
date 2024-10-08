#include <bits/stdc++.h>

# define MOD 1000000007

int add(int a, int b) {
    return (a % MOD + b % MOD) % MOD;
} 

int mul(int a, int b) {
    return (a % MOD * 1LL * b % MOD) % MOD;
} 

// Method 1: Recursion
int solve(int n, int k) {
    if(n == 1) {
        return k;
    }
    if(n == 2) {
        return add(k, mul(k, k - 1));
    }

    int ans = add(mul(solve(n - 2, k), k - 1), mul(solve(n - 1, k), k - 1));
    
    return ans;
}

int numberOfWays(int n, int k) {
    return solve(n, k);
}

// Method 2: Memoization
int solve(int n, int k, vector<int> &dp) {
    if(n == 1) {
        return k;
    }
    if(n == 2) {
        return add(k, mul(k, k - 1));
    }
    if(dp[n] != -1) {
        return dp[n];
    }

    dp[n] = add(mul(solve(n - 2, k, dp), k - 1), mul(solve(n - 1, k, dp), k - 1));
    
    return dp[n];
}

int numberOfWays(int n, int k) {
    vector<int> dp(n + 1, -1);

    return solve(n, k, dp);
}

// Method 3: Tabulation
int solve(int n, int k) {
    vector<int> dp(n + 1, 0);

    dp[1] = k;
    dp[2] = add(k, mul(k, k - 1));

    for(int i = 3; i <= n; i ++) {
        dp[i] = add(mul(dp[i - 2], k - 1), mul(dp[i - 1], k - 1));
    }
    
    return dp[n];
}

int numberOfWays(int n, int k) {

    return solve(n, k);
}

// Method 4: Space Optimization
int solve(int n, int k) {
    int prev = k;
    int curr = add(k, mul(k, k - 1));

    for(int i = 3; i <= n; i ++) {
        int ans = add(mul(prev, k - 1), mul(curr, k - 1));

        prev = curr;
        curr = ans;
    }
    
    return curr;
}

int numberOfWays(int n, int k) {

    return solve(n, k);
}