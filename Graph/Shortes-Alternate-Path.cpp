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

// https://www.codingninjas.com/codestudio/problems/shortest-alternate-colored-path_1281318

vector<int> findShortestAltenatePath(int n, vector<vector<int>> &red, vector<vector<int>> &blue) {
	vector<int> ans(n, INT_MAX);
	ans[0] = 0;
	vector<vector<pair<int, int>>> graph(n); // 0 for red, 1 for blue
	for (int i = 0; i < red.size(); i++)
		graph[red[i][0]].push_back({red[i][1], 0});
	for (int i = 0; i < blue.size(); i++) 
		graph[blue[i][0]].push_back({blue[i][1], 1});
	bool flag = false;
	priority_queue<vector<int>> q;
	vector<vector<bool>> visited(n, vector<bool>(3, false));
	visited[0][2] = true;
	q.push({0, -1, 0});
	while (!q.empty()) {
		int node = q.top()[0];
		int currColor = q.top()[1];
		int dist = q.top()[2];
		q.pop();
		for (pair<int, int> i : graph[node]) {
			if (currColor != i.second && visited[i.first][i.second] == false) {
				visited[i.first][i.second] = true;
				q.push({i.first, i.second, dist + 1});
				ans[i.first] = min(ans[i.first], dist + 1);
			}
		}
	}
	for (int i = 0; i < ans.size(); i++) if (ans[i] == INT_MAX) ans[i] = -1;
	return ans;
}

void solve() {
	int N, RED_LEN, BLUE_LEN;
	cin >> N >> RED_LEN >> BLUE_LEN;
	vector<vector<int>> red, blue;
	for (int i = 0; i < RED_LEN; i++) {
		int a, b;
		cin >> a >> b;
		red.push_back({a, b});
	}
	for (int i = 0; i < BLUE_LEN; i++) {
		int a, b;
		cin >> a >> b;
		blue.push_back({a, b});
	}
	vector<int> ans = findShortestAltenatePath(N, red, blue);
	for (auto &i : ans) cout << i << " ";
	cout << endl;
}

int main() {
	int test_case;
	cin >> test_case;
	while (test_case--) {
		solve();
	}
	return 0;
}