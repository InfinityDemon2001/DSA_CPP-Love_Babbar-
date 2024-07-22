#include <bits/stdc++.h>

// Method 1: Recursion
int solve(vector<int> &nums1, vector<int> &nums2, int index, bool swapped) {
    // Base case
    if(index == nums1.size()) {
        return 0;
    }

    int ans = INT_MAX;

    int prev1 = nums1[index - 1];
    int prev2 = nums2[index - 1];

    // Catch
    if(swapped) {
        swap(prev1, prev2);
    }

    // No swap
    if(nums1[index] > prev1 && nums2[index] > prev2) {
        ans = solve(nums1, nums2, index + 1, 0);
    }
    // Swap 
    if(nums1[index] > prev2 && nums2[index] > prev1) {
        ans = min(ans, 1 + solve(nums1, nums2, index + 1, 1));
    }

    return ans;
}

// Method 2: Memoization
int solve(vector<int> &nums1, vector<int> &nums2, int index, bool swapped, vector<vector<int>> &dp) {
    // Base case
    if(index == nums1.size()) {
        return 0;
    }
    if(dp[index][swapped] != -1) {
        return dp[index][swapped];
    }

    int ans = INT_MAX;

    int prev1 = nums1[index - 1];
    int prev2 = nums2[index - 1];

    // Catch
    if(swapped) {
        swap(prev1, prev2);
    }

    // No swap
    if(nums1[index] > prev1 && nums2[index] > prev2) {
        ans = solve(nums1, nums2, index + 1, 0, dp);
    }
    // Swap 
    if(nums1[index] > prev2 && nums2[index] > prev1) {
        ans = min(ans, 1 + solve(nums1, nums2, index + 1, 1, dp));
    }

    return dp[index][swapped] = ans;
}
    
int minSwap(vector<int> &nums1, vector<int> &nums2) {
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);

    bool swapped = 0;

    int n = nums1.size();

    vector<vector<int>> dp(n + 1, vector<int> (2, -1));

    return solve(nums1, nums2, 1, swapped, dp);
}

// Method 3: Tabulation
int solve(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size();
    vector<vector<int>> dp(n + 1, vector<int> (2, 0));

    for(int index = n - 1; index >= 1; index --) {
        for(int swapped = 1; swapped >= 0; swapped --) {
            int ans = INT_MAX;

            int prev1 = nums1[index - 1];
            int prev2 = nums2[index - 1];
        
            // Catch
            if(swapped) {
                swap(prev1, prev2);
            }
        
            // No swap
            if(nums1[index] > prev1 && nums2[index] > prev2) {
                ans = dp[index + 1][0];
            }
            // Swap 
            if(nums1[index] > prev2 && nums2[index] > prev1) {
                ans = min(ans, 1 + dp[index + 1][1]);
            }

            dp[index][swapped] = ans;
        }
    }

    return dp[1][0];
}
    
int minSwap(vector<int> &nums1, vector<int> &nums2) {
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);

    return solve(nums1, nums2);
}

// Method 4: Space Optimization
int solve(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size();
        
    int Swap = 0;
    int noswap = 0;
    int currswap = 0;
    int currnoswap = 0;

    for(int index = n - 1; index >= 1; index --) {
        for(int swapped = 1; swapped >= 0; swapped --) {
            int ans = INT_MAX;

            int prev1 = nums1[index - 1];
            int prev2 = nums2[index - 1];
        
            // Catch
            if(swapped) {
                swap(prev1, prev2);
            }
        
            // No swap
            if(nums1[index] > prev1 && nums2[index] > prev2) {
                ans = noswap;
            }
            // Swap 
            if(nums1[index] > prev2 && nums2[index] > prev1) {
                ans = min(ans, 1 + Swap);
            }

            if(swapped) {
                currswap = ans;
            }
            else {
                currnoswap = ans;
            }
        }

        Swap = currswap;
        noswap = currnoswap;
    }

    return min(Swap, noswap);
}
    
int minSwap(vector<int> &nums1, vector<int> &nums2) {
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);

    return solve(nums1, nums2);
}