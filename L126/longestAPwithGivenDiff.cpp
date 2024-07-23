#include <bits/stdc++.h>

// Method 1: Recursion
int longestSubsequence(vector<int> &arr, int difference) {
    int n = arr.size();

    int ans = 0;

    unordered_map<int, int> dp;

    for(int i = 0; i < n; i ++) {
        int prev = arr[i] - difference;

        int length_till_prev = dp[prev];

        dp[arr[i]] = 1 + length_till_prev;

        ans = max(ans, dp[arr[i]]);
    }

    return ans;
}