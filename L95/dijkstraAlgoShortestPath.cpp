#include <bits/stdc++.h>

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Create adjacency list
    unordered_map<int, list<pair<int, int>>> adj;

    for(int i = 0; i < edges; i ++) {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    // Creation of distance array with infinite value initially
    vector<int> dist(vertices, INT_MAX);
    // Creation of set on the basis of (distance, node)
    set<pair<int, int>> st;

    // Initialise distance and set with source node
    dist[source] = 0;
    st.insert(make_pair(0, source));

    while(!st.empty()) {
        // Fetch top node
        auto top = *(st.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        st.erase(st.begin());

        // Traverse on neighbours
        for(auto neighbour: adj[topNode]) {
            if(nodeDistance + neighbour.second < dist[neighbour.first]) {
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));
                // If record found, erase it
                if(record != st.end()) {
                    st.erase(record);
                }

                // Distance update
                dist[neighbour.first] = nodeDistance + neighbour.second;
                // Record push in set
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }

    return dist;
}