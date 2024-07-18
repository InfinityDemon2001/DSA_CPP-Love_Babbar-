# include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<int> &disc, vector<int> &low, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adj, vector<int> &ap, int timer) {
    vis[node] = true;
    disc[node] = low[node] = timer ++;
    int child = 0;

    for(auto nbr: adj[node]) {
        if(nbr == parent) {
            continue;
        }

        if(!vis[nbr]) {
            dfs(nbr, node, disc, low, vis, adj, ap, timer);
            low[node] = min(low[node], low[nbr]);

            // Check AP or not
            if(low[nbr] >= disc[node] && parent != -1) {
                ap[node] = 1;
            }

            child ++;
        }
        else {
            low[node] = min(low[node], disc[nbr]);
        }
    }

    if(parent == -1, child > 1) {
        ap[node] = 1;
    }
}

int main() {
    int n = 5;
    int e = 5;

    vector<pair<int, int>> edges;
    edges.push_back(make_pair(0, 3));
    edges.push_back(make_pair(3, 4));
    edges.push_back(make_pair(0, 4));
    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(1, 2));

    // Adjacency list
    unordered_map<int, list<int>> adj;

    for(int i = 0; i < e; i ++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(n, -1);
    vector<int> low(n, - 1);
    unordered_map<int, bool> vis;
    vector<int> ap(n, 0);

    // DFS
    for(int i = 0; i < n; i ++) {
        if(!vis[i]) {
            dfs(i, -1, disc, low, vis, adj, ap, timer);
        }
    }

    // Print articulation point
    cout << "Articulation Points:\n";

    for(int i = 0; i < n; i ++) {
        if(ap[i] != 0) {
            cout << i << " ";
        }
    }
    
    return 0;
}