#include <bits/stdc++.h>

int solve(string text1, string text2) {
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
    
int longestPalindromeSubseq(string s) {
    string revStr = s;

    reverse(revStr.begin(), revStr.end());

    return solve(s, revStr);
}