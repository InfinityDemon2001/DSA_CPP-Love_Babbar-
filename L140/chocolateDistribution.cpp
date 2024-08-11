#include <bits/stdc++.h>

long long findMinDiff(vector<long long> a, long long n, long long m) {
    int i = 0;
    int j = m - 1;
    int minDiff = INT_MAX;
    
    sort(a.begin(), a.end());
    
    while(j < a.size()) {
        int diff = a[j] - a[i];
        
        minDiff = min(minDiff, diff);
        
        i ++;
        j ++;
    }
    
    return minDiff;
}   