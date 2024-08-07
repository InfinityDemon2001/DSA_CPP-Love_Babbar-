#include <bits/stdc++.h>

// Method 1: Recursion
int solve(string a, string b, int i, int j) {
    if(i == a.length()) {
        return b.length() - j;
    }
    if(j == b.length()) {
        return a.length() - i;
    }

    int ans = 0;

    if(a[i] == b[j]) {
        return solve(a, b, i + 1, j + 1);
    }
    else {
        // Insert
        int insertAns = 1 + solve(a, b, i, j + 1);

        // Delete
        int deleteAns = 1 + solve(a, b, i + 1, j);

        // Replace
        int replaceAns = 1 + solve(a, b, i + 1, j + 1);

        ans = min(insertAns, min(deleteAns, replaceAns));
    }

    return ans;
}
    
int minDistance(string word1, string word2) {
    return solve(word1, word2, 0, 0);
}

// Method 2: Memoization
int solve(string a, string b, int i, int j, vector<vector<int>> &dp) {
    if(i == a.length()) {
        return b.length() - j;
    }
    if(j == b.length()) {
        return a.length() - i;
    }
    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    int ans = 0;

    if(a[i] == b[j]) {
        return solve(a, b, i + 1, j + 1, dp);
    }
    else {
        // Insert
        int insertAns = 1 + solve(a, b, i, j + 1, dp);

        // Delete
        int deleteAns = 1 + solve(a, b, i + 1, j, dp);

        // Replace
        int replaceAns = 1 + solve(a, b, i + 1, j + 1, dp);

        ans = min(insertAns, min(deleteAns, replaceAns));
    }

    return dp[i][j] = ans;
}
    
int minDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();
    vector<vector<int>> dp(m, vector<int> (n, -1));

    return solve(word1, word2, 0, 0, dp);
}

// Method 3: Tabulation
int minDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();
    vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));

    for(int j = 0; j < n; j ++) {
        dp[m][j] = n - j;
    }

    for(int i = 0; i < m; i ++) {
        dp[i][n] = m - i;
    }

    for(int i = m - 1; i >= 0; i --) {
        for(int j = n - 1; j >= 0; j --) {
            int ans = 0;

            if(word1[i] == word2[j]) {
                ans = dp[i + 1][j + 1];
            }
            else {
                // Insert
                int insertAns = 1 + dp[i][j + 1];
        
                // Delete
                int deleteAns = 1 + dp[i + 1][j];
        
                // Replace
                int replaceAns = 1 + dp[i + 1][j + 1];
        
                ans = min(insertAns, min(deleteAns, replaceAns));
            }

            dp[i][j] = ans;
        }
    }

    return dp[0][0];
}

// Method 4: Space Optimization
int solve(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();
    vector<int> curr(n + 1, 0);
    vector<int> next(n + 1, 0);

    for(int j = 0; j < n; j ++) {
        next[j] = n - j;
    }

    for(int i = m - 1; i >= 0; i --) {
        for(int j = n - 1; j >= 0; j --) {
            curr[n] = m - i;
                
            int ans = 0;

            if(word1[i] == word2[j]) {
                ans = next[j + 1];
            }
            else {
                // Insert
                int insertAns = 1 + curr[j + 1];
        
                // Delete
                int deleteAns = 1 + next[j];
        
                // Replace
                int replaceAns = 1 + next[j + 1];
        
                ans = min(insertAns, min(deleteAns, replaceAns));
            }

            curr[j] = ans;
        }

        next = curr;
    }

    return next[0];
}
    
int minDistance(string word1, string word2) {
    if(word1.length() == 0) {
        return word2.length();
    }
    if(word2.length() == 0) {
        return word1.length();
    }

    return solve(word1, word2);
}