#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &i : a) cin >> i;
	int i = 0;
	for (int i = 0; i < n; ++i) {
		a[i] = a[i] - 1;
	}
	for (int i = 0; i < n; i++) {
		a[a[i] % n] = a[a[i] % n] + n;
	}
	int index = 0;
	for (auto i : a) {
		cout << index++ + 1 << " -> " << i / n <<endl;
	}
	return 0;
}