#include<bits/stdc++.h> 
using namespace std;



bool dfs(int node, int parent, vector<vector<int>> &graph, vector<bool> &visited) {
	visited[node] = true;
	for (int neighbour : graph[node]) {
		if (!visited[neighbour]) {
			return dfs(neighbour, node, graph, visited);
		}
		else if (neighbour != parent) return true;
	}
	return false;
}

bool cycleDetection(int N, vector<vector<int>> &edges) {
	vector<vector<int>> graph(N);
	vector<bool> visited(N, false);
	for (int i = 0; i < edges.size(); i++) {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }
	for (int i = 0; i < N; i++) {
		if (!visited[i])  
			if (dfs(i, -1, graph, visited)) return true;
	}
	return false;
}

int main() {
	int N, NoOfedges;
	cin >> N >> NoOfedges;
	vector<vector<int>> edges;
	for (int i = 0; i < NoOfedges; i++) {
		int a, b;
		cin >> a >> b;
		edges.push_back({a, b});
	}
	cout << cycleDetection(N, edges) << endl;
	return 0;
}