#include <bits/stdc++.h> 

int countDistinctWays(int nStairs) {
    if(nStairs <= 1) {
        return 1;
    }

    int prev1 = 1;
    int prev2 = 1;

    for(int i = 2; i <= nStairs; i ++) {
        int curr = (prev1 + prev2) % 1000000007;

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}