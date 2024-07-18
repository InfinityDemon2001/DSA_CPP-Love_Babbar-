#include <bits/stdc++.h> 

// Method 1: Recursion
int solve(vector<int> &nums, int n) {
    // Base case
    if(n < 0) {
        return 0;
    }
    if(n == 0) {
        return nums[0];
    }

    int include = solve(nums, n - 2) + nums[n];
    int exclude = solve(nums, n - 1) + 0;

    return max(include, exclude);
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();

    return solve(nums, n - 1);
}

// Method 2: Memoization
int solve(vector<int> &nums, int n, vector<int> &dp) {
    // Base case
    if(n < 0) {
        return 0;
    }
    if(n == 0) {
        return nums[0];
    }
    if(dp[n] != -1) {
        return dp[n];
    }

    int include = solve(nums, n - 2, dp) + nums[n];
    int exclude = solve(nums, n - 1, dp) + 0;
    dp[n] = max(include, exclude);

    return dp[n];
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n + 1, -1);

    return solve(nums, n - 1, dp);
}

// Method 3: Tabulation
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];

    for(int i = 1; i < n; i ++) {
        int include = nums[i] + dp[i - 2];
        int exclude = 0 + dp[i - 1];

        dp[i] = max(include, exclude);
    }

    return dp[n - 1];
}

// Method 4: Space Optimization
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    int prev = 0;
    int curr = nums[0];

    for(int i = 1; i < n; i ++) {
        int include = nums[i] + prev;
        int exclude = 0 + curr;

        int ans = max(include, exclude);

        prev = curr;
        curr = ans;
    }

    return curr;
}