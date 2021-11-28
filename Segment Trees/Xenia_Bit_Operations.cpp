#include<bits/stdc++.h>
using namespace std;

class SegmentTree {
	vector<int> seg;
public:
	SegmentTree(int n) {
		seg.resize(4 * n);
	}

	void build(int index, int low, int high, int orr, vector<int> &a) {
		if (low == high) {
			seg[index] = a[low];
			return;
		}
		int mid = (low + high) / 2;
		build(2 * index + 1, low, mid, !orr, a);
		build(2 * index + 2, mid + 1, high, !orr, a);
		if (orr) {
			seg[index] = seg[2 * index + 1] | seg[2 * index + 2];
		}
		else {
			seg[index] = seg[2 * index + 1] ^ seg[2 * index + 2];
		}
		return;
	}
	void update(int index, int low, int high, int i, int val, int orr) {
		if (low == high) {
			seg[index] = val;
			return; 
		}
		int mid = (low + high) / 2;
		if (i <= mid) {
			update(2 * index + 1, low, mid, i, val, !orr);
		}
		else {
			update(2 * index + 2, mid + 1, high, i, val, !orr);
		}
		if (orr) {
			seg[index] = seg[2 * index + 1] | seg[2 * index + 2];
		}
		else {
			seg[index] = seg[2 * index + 1] ^ seg[2 * index + 2];
		}
	}
	void print() {
		cout << seg[0] << endl;
	}
};

void solve() {
	int n, m;
	cin >> n >> m;
	int x = n;
	n = pow(2, n);
	vector<int> a(n);
	SegmentTree s(n);
	for (auto &i : a) cin >> i;
	if (x % 2) {
		s.build(0, 0, n - 1, 1, a);
	}
	else s.build(0, 0, n - 1, 0, a);
	while (m--) {
		int i, val;
		cin >> i >> val;
		i -= 1;
		if (x % 2) s.update(0, 0, n - 1, i, val, 1);
		else s.update(0, 0, n - 1, i, val, 0);
		s.print();
	}
}

int main() {
	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}
}