#include <bits/stdc++.h>

// Method 1: Recursion
bool solve(string &str, string &pattern, int i, int j) {
    if(i < 0 && j < 0) {
        return true;
    }
    if(j < 0 && i >= 0) {
        return false;
    }
    if(i < 0 && j >= 0) {
        for(int k = 0; k <= j; k ++) {
            if(pattern[k] != '*') {
                return false;
            }
        }

        return true;
    }

    if(str[i] == pattern[j] || pattern[j] == '?') {
        return solve(str, pattern, i - 1, j - 1);
    }
    else if(pattern[j] == '*') {
        return solve(str, pattern, i - 1, j) || solve(str, pattern, i, j - 1);
    }
    else {
        return false;
    }
}
    
bool isMatch(string s, string p) {
    return solve(s, p, s.length() - 1, p.length() - 1);
}

// Method 2: Memoization
bool solve(string &str, string &pattern, int i, int j, vector<vector<int>> &dp) {
    if(i < 0 && j < 0) {
        return true;
    }
    if(j < 0 && i >= 0) {
        return false;
    }
    if(i < 0 && j >= 0) {
        for(int k = 0; k <= j; k ++) {
            if(pattern[k] != '*') {
                return false;
            }
        }

        return true;
    }
    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    if(str[i] == pattern[j] || pattern[j] == '?') {
        return dp[i][j] = solve(str, pattern, i - 1, j - 1, dp);
    }
    else if(pattern[j] == '*') {
        return dp[i][j] = solve(str, pattern, i - 1, j, dp) || solve(str, pattern, i, j - 1, dp);
    }
    else {
        return dp[i][j] = false;
    }
}
    
bool isMatch(string s, string p) {
    int m = s.length();
    int n = p.length();
    vector<vector<int>> dp(m, vector<int> (n, -1));

    return solve(s, p, m - 1, n - 1, dp);
}

// Method 3: Tabulation
bool solve(string str, string pattern) {
    int m = str.length();
    int n = pattern.length();
    vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));

    dp[0][0] = true;

    for(int j = 1; j <= n; j ++) {
        bool flag = true;

        for(int k = 1; k <= j; k ++) {
            if(pattern[k - 1] != '*') {
                flag = false;
                break;
            }
        }

        dp[0][j] = flag;
    }

    for(int i = 1; i <= m; i ++) {
        for(int j = 1; j <= n; j ++) {
            if(str[i - 1] == pattern[j - 1] || pattern[j - 1] == '?') {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if(pattern[j - 1] == '*') {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
            else {
                dp[i][j] = false;
            }
        }
    }

    return dp[m][n];
}
    
bool isMatch(string s, string p) {
    return solve(s, p);
}

// Method 4: Space Optimization
bool isMatch(string s, string p) {
    int m = s.length();
    int n = p.length();
    vector<int> curr(n + 1, 0);
    vector<int> prev(n + 1, 0);
        
    prev[0] = true;

    for(int j = 1; j <= n; j ++) {
        bool flag = true;

        for(int k = 1; k <= j; k ++) {
            if(p[k - 1] != '*') {
                flag = false;

                break;
            }
        }

        prev[j] = flag;
    }

    for(int i = 1; i <= m; i ++) {
        for(int j = 1; j <= n; j ++) {
            if(s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                curr[j] = prev[j - 1];
            }
            else if(p[j - 1] == '*') {
                curr[j] = prev[j] || curr[j - 1];
            }
            else {
                curr[j] = false;
            }
        }

        prev = curr;
    }

    return prev[n];
}