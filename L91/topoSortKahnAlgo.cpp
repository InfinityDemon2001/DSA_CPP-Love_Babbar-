#include <bits/stdc++.h> 

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
    // Create adj list
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // Find all indegrees
    vector<int> indegree(v);

    for (auto i:adj) {
        for(auto j:i.second) {
            indegree[j] ++;
        }
    }

    // Push 0 indegree elements into queue
    queue<int> q;

    for(int i = 0; i < v; i ++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    // BFS
    vector<int> ans;

    while(!q.empty()) {
        int front = q.front();
        q.pop();

        // Store answer
        ans.push_back(front);

        // Neighbour indegree update
        for(auto neighbour:adj[front]) {
            indegree[neighbour] --;
            if(indegree[neighbour] == 0) {
                q.push(neighbour);
            }
        }
    }

    return ans;
}
