#include <bits/stdc++.h>

// Method 1: Recursion
int solve(int n, vector<int> &days, vector<int> &cost, int index) {
    // Base case
    if(index >= n) {
        return 0;
    }

    // 1 day pass
    int opt1 = cost[0] + solve(n, days, cost, index + 1);

    int i;
    
    // 7 day pass
    for(i = index; i < n && days[i] < days[index] + 7; i ++);

    int opt2 = cost[1] + solve(n, days, cost, i);

    // 30 day pass
    for(i = index; i < n && days[i] < days[index] + 30; i ++);

    int opt3 = cost[2] + solve(n, days, cost, i);

    return min(opt1, min(opt2, opt3));
}

int minimumCoins(int n, vector<int> days, vector<int> cost) {
    return solve(n, days, cost, 0);
}

// Method 2: Memoization
int solve(int n, vector<int> &days, vector<int> &cost, int index, vector<int> &dp) {
    // Base case
    if(index >= n) {
        return 0;
    }
    if(dp[index] != -1) {
        return dp[index];
    }

    // 1 day pass
    int opt1 = cost[0] + solve(n, days, cost, index + 1, dp);

    int i;
    
    // 7 day pass
    for(i = index; i < n && days[i] < days[index] + 7; i ++);

    int opt2 = cost[1] + solve(n, days, cost, i, dp);

    // 30 day pass
    for(i = index; i < n && days[i] < days[index] + 30; i ++);

    int opt3 = cost[2] + solve(n, days, cost, i, dp);

    dp[index] = min(opt1, min(opt2, opt3));

    return dp[index];
}

int minimumCoins(int n, vector<int> days, vector<int> cost) {
    vector<int> dp(n + 1, -1);

    return solve(n, days, cost, 0, dp);
}

// Method 3: Tabulation
int solve(int n, vector<int> &days, vector<int> &cost) {
    vector<int> dp(n + 1, INT_MAX);

    dp[n] = 0;

    for(int k = n - 1; k >= 0; k --) {
        // 1 day pass
        int opt1 = cost[0] + dp[k + 1];
    
        int i;
        
        // 7 day pass
        for(i = k; i < n && days[i] < days[k] + 7; i ++);
    
        int opt2 = cost[1] + dp[i];
    
        // 30 day pass
        for(i = k; i < n && days[i] < days[k] + 30; i ++);
    
        int opt3 = cost[2] + dp[i];
    
        dp[k] = min(opt1, min(opt2, opt3));
    }

    return dp[0];
}

int minimumCoins(int n, vector<int> days, vector<int> cost) {
    return solve(n, days, cost);
}

// Method 4: Space Optimization
int minimumCoins(int n, vector<int> days, vector<int> cost) {
    int ans = 0;

    queue<pair<int, int>> week;
    queue<pair<int, int>> month;

    for(int day: days) {
        // Step 1: Remove expired days
        while(!week.empty() && week.front().first + 7 <= day) {
            week.pop();
        }
        while(!month.empty() && month.front().first + 30 <= day) {
            month.pop();
        }

        // Step 2: Add cost for current day
        week.push(make_pair(day, cost[1] + ans));
        month.push(make_pair(day, cost[2] + ans));

        // Step 3: Update answer
        ans = min(cost[0] + ans, min(week.front().second, month.front().second));
    }

    return ans;
}