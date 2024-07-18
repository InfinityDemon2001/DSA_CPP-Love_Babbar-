#include <bits/stdc++.h> 

long long int solve(vector<int> &nums){
    int n = nums.size();
    long long int prev = 0;
    long long int curr = nums[0];

    for(int i = 1; i < n; i ++) {
        long long int include = nums[i] + prev;
        long long int exclude = 0 + curr;

        long long int ans = max(include, exclude);

        prev = curr;
        curr = ans;
    }

    return curr;
}

long long int houseRobber(vector<int>& valueInHouse) {
    int n = valueInHouse.size();

    if(n == 1) {
        return valueInHouse[0];
    }
    
    vector<int> first;
    vector<int> second;

    for(int i = 0; i < n; i ++) {
        if(i != n - 1) {
            first.push_back(valueInHouse[i]);
        } 
        if(i != 0) {
            second.push_back(valueInHouse[i]);
        } 
    }

    return max(solve(first), solve(second));
}