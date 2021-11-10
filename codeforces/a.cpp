#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	string keyboard;
	cin >> keyboard;
	string s;
	cin >> s;
	int ans = 0;
	unordered_map<char, int> m;
	for (int i = 0; i < keyboard.length(); i++) {
		m[keyboard[i]] = i+1;
	}
	for (int i = 1; i < s.length(); i++) {
		ans += abs(m[s[i-1]] - m[s[i]]);
	}
	cout << ans << endl;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}