#include <bits/stdc++.h>

// Method 1: Recursion
int solve(string a, string b, int i, int j) {
    if(i == a.length() || j == b.length()) {
        return 0;
    }

    int ans = 0;

    if(a[i] == b[j]) {
        ans = 1 + solve(a, b, i + 1, j + 1);
    }
    else {
        ans = max(solve(a, b, i + 1, j), solve(a, b, i, j + 1));
    }

    return ans;
}
    
int longestCommonSubsequence(string text1, string text2) {
    return solve(text1, text2, 0, 0);
}

// Method 2: Memoization
int solve(string a, string b, int i, int j, vector<vector<int>> &dp) {
    if(i == a.length() || j == b.length()) {
        return 0;
    }
    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    int ans = 0;

    if(a[i] == b[j]) {
        ans = 1 + solve(a, b, i + 1, j + 1, dp);
    }
    else {
        ans = max(solve(a, b, i + 1, j, dp), solve(a, b, i, j + 1, dp));
    }

    return dp[i][j] = ans;
}
    
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();
    vector<vector<int>> dp(m, vector<int> (n, -1));

    return solve(text1, text2, 0, 0, dp);
}

// Method 3: Tabulation
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();
    vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));

    for(int i = m - 1; i >= 0; i --) {
        for(int j = n - 1; j >= 0; j --) {
            int ans = 0;

            if(a[i] == b[j]) {
                ans = 1 + dp[i + 1][j + 1];
            }
            else {
                ans = max(dp[i + 1][j], dp[i][j + 1]);
            }

            dp[i][j] = ans;
        }
    }

    return dp[0][0];
}

// Method 4: Space Optimization
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();
    vector<int> curr(n + 1, 0);
    vector<int> next(n + 1, 0);

    for(int i = m - 1; i >= 0; i --) {
        for(int j = n - 1; j >= 0; j --) {
            int ans = 0;

            if(text1[i] == text2[j]) {
                ans = 1 + next[j + 1];
            }
            else {
                ans = max(next[j], curr[j + 1]);
            }

            curr[j] = ans;
        }

        next = curr;
    }

    return next[0];
}