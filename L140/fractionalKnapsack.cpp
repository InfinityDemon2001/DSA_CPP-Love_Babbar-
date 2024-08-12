#include <bits/stdc++.h>

static bool cmp(pair<double, Item> a, pair<double, Item> b) {
    return a.first > b.first;
}

double fractionalKnapsack(int w, Item arr[], int n) {
    vector<pair<double, Item>> v;
    
    for(int i = 0; i < n; i ++) {
        double valuePerUnit = (1.0 * arr[i].value) / arr[i].weight;
        
        pair<double, Item> p = make_pair(valuePerUnit, arr[i]);
        
        v.push_back(p);
    }
    
    sort(v.begin(), v.end(), cmp);
    
    double totalValue = 0;
    
    for(int i = 0; i < n; i ++) {
        if(v[i].second.weight > w) {
            totalValue += w * v[i].first;
            w = 0;
        }
        else {
            totalValue += v[i].second.value;
            w -= v[i].second.weight;
        }
    }
    
    return totalValue;
}