#include <bits/stdc++.h>

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	// Create adjacency list
	unordered_map<int, list<int>> adjList;

	for(int i = 0; i < m; i ++) {
		int u = edges[i].first;
		int v = edges[i].second;

		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	// Do BFS
	unordered_map<int, bool> visited;
	unordered_map<int, int> parent;
	queue<int> q;

	q.push(s);
	visited[s] = true;
	parent[s] = -1;

	while(!q.empty()) {
		int front = q.front();
		q.pop();

		for(auto i:adjList[front]) {
			if(!visited[i]) {
				visited[i] = true;
				parent[i] = front;
				q.push(i);
			}
		}
	}

	// Prepare shortest path
	vector<int> ans;
	int currentNode = t;
	ans.push_back(t);

	while(currentNode != s) {
		currentNode = parent[currentNode];
		ans.push_back(currentNode);
	}
	reverse(ans.begin(), ans.end());
	return ans;
}