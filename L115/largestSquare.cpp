#include <bits/stdc++.h>

// Method 1: Recursion
int solve(vector<vector<int>> &mat, int n, int m, int &maxi, int i, int j) {
    if(i >= n || j >= m) {
        return 0;
    }
    
    int right = solve(mat, n, m, maxi, i, j + 1);
    int diagonal = solve(mat, n, m, maxi, i + 1, j + 1);
    int down = solve(mat, n, m, maxi, i + 1, j);
    
    if(mat[i][j]) {
        int ans = 1 + min(right, min(down, diagonal));
        
        maxi = max(maxi, ans);
        
        return ans;
    }
    
    return 0;
}

int maxSquare(int n, int m, vector<vector<int>> mat) {
    int maxi = 0;
    
    solve(mat, n, m, maxi, 0, 0);
    
    return maxi;
}

// Method 2: Memoization
int solve(vector<vector<int>> &mat, int n, int m, int &maxi, int i, int j, vector<vector<int>> &dp) {
    if(i >= n || j >= m) {
        return 0;
    }
    if(dp[i][j] != -1) {
        return dp[i][j];
    } 
    
    int right = solve(mat, n, m, maxi, i, j + 1, dp);
    int diagonal = solve(mat, n, m, maxi, i + 1, j + 1, dp);
    int down = solve(mat, n, m, maxi, i + 1, j, dp);
    
    if(mat[i][j]) {
        dp[i][j] = 1 + min(right, min(down, diagonal));
        
        maxi = max(maxi, dp[i][j]);
        
        return dp[i][j];
    }
    
    return dp[i][j] = 0;
}

int maxSquare(int n, int m, vector<vector<int>> mat) {
    int maxi = 0;
    vector<vector<int>> dp(n, vector<int> (m, -1));
    
    solve(mat, n, m, maxi, 0, 0, dp);
    
    return maxi;
}

// Method 3: Tabulation
void solve(vector<vector<int>> &mat, int n, int m, int &maxi) {
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    
    for(int i = n - 1; i >= 0; i --) {
        for(int j = m - 1; j >= 0; j --) {
            int right = dp[i][j + 1];
            int diagonal = dp[i + 1][j + 1];
            int down = dp[i + 1][j];
            
            if(mat[i][j]) {
                dp[i][j] = 1 + min(right, min(down, diagonal));
                
                maxi = max(maxi, dp[i][j]);
            }
            else {
                dp[i][j] = 0;
            }
        }
    }
}

int maxSquare(int n, int m, vector<vector<int>> mat) {
    int maxi = 0;
    
    solve(mat, n, m, maxi);
    
    return maxi;
}

// Method 4: Space Optimization
void solve(vector<vector<int>> &mat, int n, int m, int &maxi) {
    vector<int> curr(m + 1, 0);
    vector<int> next(m + 1, 0);
    
    for(int i = n - 1; i >= 0; i --) {
        for(int j = m - 1; j >= 0; j --) {
            int right = curr[j + 1];
            int diagonal = next[j + 1];
            int down = next[j];
            
            if(mat[i][j]) {
                curr[j] = 1 + min(right, min(down, diagonal));
                
                maxi = max(maxi, curr[j]);
            }
            else {
                curr[j] = 0;
            }
        }
        
        next = curr;
    }
}

int maxSquare(int n, int m, vector<vector<int>> mat) {
    int maxi = 0;
    
    solve(mat, n, m, maxi);
    
    return maxi;
}