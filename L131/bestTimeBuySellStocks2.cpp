#include <bits/stdc++.h>

// Method 1: Recursion
int solve(int index, int buy, vector<int> &prices) {
    if(index >= prices.size()) {
        return 0;
    }

    int profit = 0;

    if(buy) {
        profit = max((-prices[index] + solve(index + 1, 0, prices)), (0 + solve(index + 1, 1, prices)));
    }
    else {
        profit = max((prices[index] + solve(index + 1, 1, prices)), (0 + solve(index + 1, 0, prices)));
    }

    return profit;
}
    
int maxProfit(vector<int> &prices) {
    return solve(0, 1, prices);
}

// Method 2: Memoization
int solve(int n, int index, int buy, vector<int> &prices, vector<vector<int>> &dp) {
    if(index >= n) {
        return 0;
    }
    if(dp[index][buy] != -1) {
        return dp[index][buy];
    }

    int profit = 0;

    if(buy) {
        profit = max((-prices[index] + solve(n, index + 1, 0, prices, dp)), (0 + solve(n, index + 1, 1, prices, dp)));
    }
    else {
        profit = max((prices[index] + solve(n, index + 1, 1, prices, dp)), (0 + solve(n, index + 1, 0, prices, dp)));
    }

    return dp[index][buy] = profit;
}
    
int maxProfit(vector<int> &prices) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int> (2, -1));
        
    return solve(n, 0, 1, prices, dp);
}

// Method 3: Tabulation
int solve(vector<int> &prices) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int> (2, 0));

    for(int index = n - 1; index >= 0; index --) {
        for(int buy = 0; buy <= 1; buy ++) {
            int profit = 0;

            if(buy) {
                profit = max((-prices[index] + dp[index + 1][0]), (0 + dp[index + 1][1]));
            }
            else {
                profit = max((prices[index] + dp[index + 1][1]), (0 + dp[index + 1][0]));
            }

            dp[index][buy] = profit;
        }
    }

    return dp[0][1];
}
    
int maxProfit(vector<int> &prices) {
    return solve(prices);
}

// Method 4: Space Optimization
int solve(vector<int> &prices) {
    int n = prices.size();
    vector<int> curr(2, 0);
    vector<int> next(2, 0);
    
    for(int index = n - 1; index >= 0; index --) {
        for(int buy = 0; buy <= 1; buy ++) {
            int profit = 0;
    
            if(buy) {
                profit = max((-prices[index] + next[0]), (0 + next[1]));
            }
            else {
                profit = max((prices[index] + next[1]), (0 + next[0]));
            }
    
            curr[buy] = profit;
        }
    
        next = curr;
    }
    
    return next[1];
}
        
int maxProfit(vector<int> &prices) {
    return solve(prices);
}