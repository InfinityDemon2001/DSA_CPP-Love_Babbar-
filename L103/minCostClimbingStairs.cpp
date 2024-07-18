// Method 1: Memoization
int solve(vector<int> &dp, vector<int> &cost, int n) {
    if(n <= 1) {
        return cost[n];
    }

    if(dp[n] != -1) {
        return dp[n];
    }

    dp[n] = min(solve(dp, cost, n - 1), solve(dp, cost, n - 2)) + cost[n];
    
    return dp[n]; 
}

int minCostClimbingStairs(vector<int> &cost) {
    int n = cost.size();
    vector<int> dp(n + 1, -1);
    
    int ans = min(solve(dp, cost, n - 1), solve(dp, cost, n - 2));
    
    return ans;
}

// Method 2: Tabulation
int solve(vector<int> &cost, int n) {
    int prev = cost[0]; 
    int curr = cost[1];

    for(int i = 2; i < n; i ++) {
        int temp = min(curr, prev) + cost[i];
        prev = curr;
        curr = temp;
    }
    
    return min(prev, curr); 
}

int minCostClimbingStairs(vector<int> &cost) {
    int n = cost.size();
    
    return solve(cost, n);
}