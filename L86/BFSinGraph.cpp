#include <bits/stdc++.h>

vector<int> bfsTraversal(int n, vector<vector<int>> &adj) { 
    vector<int> ans;
    queue<int> q;
    unordered_map<int,bool> visited;
    
    q.push(0);
    visited[0] = true;

    while(!q.empty()) {
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);

        for(int i = 0; i < adj[frontNode].size() ; i ++) {
            int next = adj[frontNode][i];

            if(visited[next] != true) {
                q.push(next);
                visited[next] = true;
            }
        }
    }

    return ans;
}