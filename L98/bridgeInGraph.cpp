#include <bits/stdc++.h>

void dfs(int node, int parent, int timer, vector<int> &disc, vector<int> &low, vector<vector<int>> &result, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis) {
    vis[node] = true;
    disc[node] = low[node] = timer ++;

    for(auto neighbour:adj[node]) {
        if(neighbour == parent) {
            continue;
        }
        if(!vis[neighbour]) {
            dfs(neighbour, node, timer, disc, low, result, adj, vis);
            low[node] = min(low[node], low[neighbour]);

            // Check if edge is bridge
            if(low[neighbour] > disc[node]) {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(neighbour);
                result.push_back(ans);
            }
        }
        else {
            // Node already visited and not parent
            // Back edge
            low[node] = min(low[node], disc[neighbour]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Adjacency list
    unordered_map<int, list<int>> adj;

    for(int i = 0; i < e; i ++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    int parent = -1;
    unordered_map<int, bool> vis;

    vector<vector<int>> result;

    // DFS
    for(int i = 0; i < v; i ++) {
        if(!vis[i]) {
            dfs(i, parent, timer, disc, low, result, adj, vis);
        }
    }

    return result;
}