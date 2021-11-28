#include<bits/stdc++.h>
using namespace std;

class SegmentTree {

	private: 
		vector<int> seg;
	public:
		SegmentTree(int n) {
			seg.resize(4 * n + 1);
		}
		void build(int index, int low, int high, vector<int> &a) {
			if (low == high) {
				seg[index] = a[low];
				return;
			}
			int mid = (low + high) / 2;
			build(2 * index + 1, low, mid, a);
			build(2 * index + 2, mid + 1, high, a);
			seg[index] = min(seg[2*index + 1], seg[2*index + 2]);
		}

		int query(int index, int low, int high, int l, int r) {
			// outside of range then return infinity 
			if (r < low || l > high) return INT_MAX;
			// if in the correct range then return seg[index];
			if (low >= l && high <= r) return seg[index];
			int mid = (low + high) / 2;
			int left = query(2 * index + 1, low, mid, l, r);
			int right = query(2 * index + 2, mid + 1, high, l, r);
			return min(left, right);
		}

		void update(int i, int val, int index, int low, int high) {
			if (low == high) {
				seg[index] = val;
				return;
			}
			int mid = (low + high) / 2;
			if (i <= mid) update(i, val, 2 * index + 1, low, mid);
			else update(i, val, 2 * index + 2, mid + 1, high);
			seg[index] = min(seg[2 * index + 1], seg[2 * index + 2]);
		}
		void printTree() {
			for (auto i : seg) cout << i << " ";
			cout << endl;
		}
};

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &i : a) cin >> i;
	SegmentTree st(n);
	st.build(0, 0, n - 1, a);
	cout << st.query(0, 0, n - 1, 2, 5);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}