#include<bits/stdc++.h>
using namespace std;

// Link : https://leetcode.com/problems/jump-game-iv/

int jumpGame(vector<int> &a) {
	int n = a.size();
	queue<pair<int, int>> q;
	vector<int> visited(n, 0);
	unordered_map<int, vector<int>> m;
	for (int i = 0; i < n; i++) {
		m[a[i]].push_back(i);
	}

	q.push({0, 0});
	visited[0] = 1;
	while (!q.empty()) {
		int node = q.front().first;
		int distance = q.front().second;
		q.pop();
		if (node == n - 1) {
			return distance;
		}
		if (node + 1 > n && !visited[node + 1]) {
			q.push({node + 1, distance + 1});
			visited[node + 1] = 1;
		}
		if (node - 1 >= 0 && !visited[node - 1]) {
			q.push({node - 1, distance + 1});
			visited[node - 1] = 1;
		}
		for (auto &i : m[a[node]]) {
			if (!visited[i]) {
				visited[i] = 1;
				q.push({i, distance + 1});
			}
		}
	}
	return INT_MAX;
}

void solve() {
	int N;
	cin >> N;
	vector<int> a(N);
	for (auto &i : a) cin >> i;
	int ans = jumpGame(a);
	cout << ans << endl;
}

int main() {
	int test_case;
	cin >> test_case;
	while (test_case--) {
		solve();
	}
	return 0;
}	