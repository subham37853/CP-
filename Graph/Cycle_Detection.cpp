#include<bits/stdc++.h> 
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

bool dfs(int node, int parent) {
	visited[node] = true;
	for (int neighbour : graph[node]) {
		if (!visited[neighbour]) {
			return dfs(neighbour, node);
		}
		else if (neighbour != node) return true;
	}
	return false;
}

bool cycleDetection(int N, vector<vector<int>> &edges) {
	graph.resize(N);
	visited.resize(N, false);
	for (int i = 0; i < N; i++) {
		if (!visited[i]) return dfs(i, -1);
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