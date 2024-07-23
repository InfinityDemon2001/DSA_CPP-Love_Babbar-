#include <bits/stdc++.h>

// Method 1: Recursion
int numTrees(int n) {
    if(n <= 1) {
        return 1;
    }

    int ans = 0;

    // Consider i as a root node
    for(int i = 1; i <= n; i ++) {
        ans += numTrees(i - 1) * numTrees(n - i);
    }

    return ans;
}

// Method 2: Memoization
int solve(int n, vector<int> &dp) {
    if(n <= 1) {
        return 1;
    }
    if(dp[n] != -1) {
        return dp[n];
    }

    int ans = 0;

    // Consider i as a root node
    for(int i = 1; i <= n; i ++) {
        ans += solve(i - 1, dp) * solve(n - i, dp);
    }

    return dp[n] = ans;
}

int numTrees(int n) {
    vector<int> dp(n + 1, -1);

    return solve(n, dp);
}

// Method 3: Tabulation
int solve(int n) {
    vector<int> dp(n + 1, 0);

    dp[0] = dp[1] = 1;

    // Consider i as the total nodes
    for(int i = 2; i <= n; i ++) {
        // j is the root node
        for(int j = 1; j <= i; j ++) {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }

    return dp[n];
}

int numTrees(int n) {
    return solve(n);
}