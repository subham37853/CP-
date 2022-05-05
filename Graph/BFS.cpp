#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
const int MOD = 1e9 + 7;
int add (int a, int b) { return ((a % MOD) + (b % MOD)) % MOD; }
int sub(int a, int b) { return ((a % MOD) - (b % MOD)) % MOD; }
int multi(int a, int b) { return ((a % MOD) * (b % MOD)) % MOD; }
int fpow(int x, int y) {
	int res = 1;
    x = x % MOD; 
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1) res = (res*x) % MOD;
        y = y>>1;
        x = (x*x) % MOD;
    }
    return res;
}

void bfs(vector<vector<int>> &graph, int V) {
	vector<bool> visited(V + 1, false);
	for (int i = 1; i <= V; i++) {
		if (visited[i]) continue;
		int root = i;
		queue<int> q;
		q.push(root);
		visited[root] = true;
		
		while (!q.empty()) {
			int queueSize = q.size();
			for (int i = 0; i < queueSize; i++) {
				int currNode = q.front();
				cout << currNode << " ";
				q.pop();
				for (int neigh : graph[currNode]) {
					if (!visited[neigh]) {
						visited[neigh] = true;
						q.push(neigh);
					}
				}
			}
		}
		cout << endl;
	}
}

void dfsHelper(vector<vector<int>> &graph, vector<bool> &visited, int node) {
	if (visited[node]) return;
	visited[node] = true;
	cout << node << " ";
	for (int neigh : graph[node]) {
		if (!visited[neigh]) {
			dfsHelper(graph, visited, neigh);
		}
	}
	return;
}

void dfs(vector<vector<int>> &graph, int V) {
	vector<bool> visited(V + 1, false);
	for (int node = 1; node <= V; node++) {
		if (!visited[node])
			dfsHelper(graph, visited, node);
		cout << endl;
	}
}

void test_case(){
	int V, E;
	cin >> V >> E;
	vector<vector<int>> graph(V + 1);
	
	for (int i = 0; i < E; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	bfs(graph, V);
	// dfs(graph, V);
}

int main() {
	int T = 1;
	// scanf("%d", &T);
	while(T--) {
		test_case();
	}
}
