# define MOD 1000000007

# include <bits/stdc++.h>

// Method 1: Recursion
long long int countDerangements(int n) {
    // Base case
    if(n == 1) {
        return 0;
    }
    if(n == 2) {
        return 1;
    }

    return (((n - 1) % MOD) * ((countDerangements(n - 1) % MOD) + (countDerangements(n - 2) % MOD)) % MOD);
}

// Method 2: Memoization
long long int solve(int n, vector<long long int> &dp) {
    if(n == 1) {
        return 0;
    }
    if(n == 2) {
        return 1;
    }
    if(dp[n] != -1) {
        return dp[n];
    }

    dp[n] = (((n - 1) % MOD) * ((solve(n - 1, dp) % MOD) + (solve(n - 2, dp) % MOD)) % MOD);

    return dp[n];
}

long long int countDerangements(int n) {
    vector<long long int> dp(n + 1, -1);

    return solve(n, dp);
}

// Method 3: Tabulation
long long int countDerangements(int n) {
    vector<long long int> dp(n + 1, 0);
    dp[1] = 0;
    dp[2] = 1;

    for(int i = 3; i < n + 1; i ++) {
        dp[i] = (((i - 1) % MOD) * ((dp[i - 1] % MOD) + (dp[i - 2] % MOD)) % MOD) % MOD;
    }

    return dp[n];
}

// Method 4: Space Optimization
long long int countDerangements(int n) {
    long long int prev = 0;
    long long int curr = 1;

    for(int i = 3; i <= n; i ++) {
        long long int ans = (((i - 1) % MOD) * ((prev % MOD) + (curr % MOD)) % MOD) % MOD;

        prev = curr;
        curr = ans;
    }

    return curr;
}