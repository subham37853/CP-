#include<bits/stdc++.h>
using namespace std;

class BinaryLifting {
private:
	vector<vector<int>> up; // up[i][j] = 2 ^ jth ancestor of node i;
	int LOG = 25; // this is 25 as Log of values upto 1 billion will come under this.
	vector<int> depth;
public:
	BinaryLifting(int n, vector<int> &parent) {
		build(n, parent);
	}
	void build(int n, vector<int> &parent) {
		depth.resize(n, 0);
		up.resize(n, vector<int> (LOG, 0));
		up[0][0] = 0;
		for (int i = 1; i < n; i++) {
			up[i][0] = parent[i];
		}
		for (int i = 0; i < n; i++) {
			if (i != 0) {
				depth[i] = depth[parent[i]] + 1;
			}
			for (int j = 1; j < LOG; j++) {
				int previousAncestor = up[i][j-1];
				up[i][j] = up[previousAncestor][j-1];
			}
		}
	}
	int findKthAncestor(int node, int k) {
		if (depth[node] < k) return -1;
		for (int i = LOG - 1; i >= 0; i--) {
			int canJump = (1 << i);
			if (k >= canJump) {
				node = up[node][i];
				k -= canJump;
			} 
		}
		return node;
	}
};

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &i : a) cin >> i;
	BinaryLifting bl(n, a);
	int node, k;
	cin >> node >> k;
	cout << bl.findKthAncestor(node, k) << "\n";
	return 0;
}