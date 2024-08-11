#include <bits/stdc++.h>

static bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int maximumMeetings(vector<int> &start, vector<int> &end) {
    vector<pair<int, int>> v;
    int n = start.size();

    for(int i = 0; i < n; i ++) {
        pair<int, int> p = make_pair(start[i], end[i]);

        v.push_back(p);
    }

    sort(v.begin(), v.end(), cmp);

    int count = 1;
    int ending = v[0].second;

    for(int i = 1; i < n; i ++) {
        if(v[i].first > ending) {
            count ++;
            ending = v[i].second;
        }
    }

    return count;
}