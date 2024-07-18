# include <bits/stdc++.h>

void dfs(int node, unordered_map<int, bool> &vis, stack<int> &s, unordered_map<int, list<int>> &adj) {
	vis[node] = true;

	for(auto nbr: adj[node]) {
		if(!vis[nbr]) {
			dfs(nbr, vis, s, adj);
		}
	}

	//Topo logic
	s.push(node);
}

void revDFS(int top, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &transpose) {
	vis[top] = true;

	for(auto nbr: transpose[top]) {
		if(!vis[nbr]) {
			revDFS(nbr, vis, transpose);
		}
	}
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges) {
	// Adjacency List
	unordered_map<int, list<int>> adj;

	for(int i = 0; i < edges.size(); i ++) {
		int x = edges[i][0];
		int y = edges[i][1];

		adj[x].push_back(y);
	}

	// Topological sort
	stack<int> s;
	unordered_map<int, bool> vis;

	for(int i = 0; i < v; i ++) {
		if(!vis[i]) {
			dfs(i, vis, s, adj);
		}
	}

	// Create transpose of graph
	unordered_map<int, list<int>> transpose;

	for(int i = 0; i < v; i ++) {
		vis[i] = 0;

		for(auto nbr: adj[i]) {
			transpose[nbr].push_back(i);
		}
	}

	// DFS call using above ordering
	int count = 0;

	while(!s.empty()) {
		int top = s.top();
		s.pop();

		if(!vis[top]) {
			count ++;
			revDFS(top, vis, transpose);
		}
	}

	return count;
}