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

string minWindowSubstring(string s, string t) {
	int currLength = INT_MAX;
	int j = 0, start = 0, cnt = 0;
	unordered_map<char, int> m;
	for (auto i : t) m[i] += 1;
	cnt = m.size();
	for (int i = 0; i < s.length(); i++) {
		if (m.find(s[i]) != m.end()) {
			m[s[i]] -= 1;
			if (m[s[i]] == 0) cnt -= 1;
		}
		if (cnt == 0) {
			if (currLength > i - start + 1) {
				currLength = i - start + 1;
				j = start;
			}
			while (cnt == 0) {
				if (m.find(s[start]) != m.end()) {
					if (m[s[start]] <= 0) m[s[start]]++;
					if (m[s[start]] > 0) cnt += 1;
				}
				start += 1;
				if (cnt == 0 && currLength > i - start + 1) {
					currLength = i - start + 1;
					j = start;
				}
			}
		}
	}
	debug(j, currLength);
	return (currLength == INT_MAX) ? "" : s.substr(j, currLength);
}

void test_case(){
	string s;
	string t;
	cin >> s;
	cin >> t;
	string ans = minWindowSubstring(s, t);
	cout << ans << endl;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}
