#include<bits/stdc++.h>
using namespace std;

bool mColoring(int colors, int V, vector<vector<int>> &edges) {
	vector<vector<int>> graph(V);
	vector<int> colorCount(V, 1);
	int maxColors = 1;
	// constructing the graph using the edges;
	for (int i = 0; i < edges.size(); i++) {
		graph[edges[i][0]].push_back(edges[i][1]);
		graph[edges[i][1]].push_back(edges[i][0]);
	}

	// Now applying BFS for every nodes 
	vector<bool> visited(V, false);
	for (int i = 0; i < V; i++) {
		if (visited[i] == true) continue;
		visited[i] = true;
		queue<int> q;
		q.push(i);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (int v : graph[u]) {
				if (colorCount[u] == colorCount[v]) {
					colorCount[v] += 1;
				}
				maxColors = max(maxColors, colorCount[v]);
				if (maxColors > colors) return false;
				if (!visited[v]) {
					visited[v] = true;
					q.push(v);
				}
			}
		}
	}
	return true;
}

int main() {
	int n, colors; // colors is the maximum number of colors we have to fill the graph
	cin >> n >> colors; 
	int noOfEgdes;
	cin >> noOfEgdes;
	vector<vector<int>> edges;
	for (int i = 0; i < noOfEgdes; i++) {
		int x, y;
		cin >> x >> y;
		edges.push_back({x, y}); // setting the graph
	}
	bool ans = mColoring(colors, n, edges);
	cout << ans << endl;
	return 0;
}