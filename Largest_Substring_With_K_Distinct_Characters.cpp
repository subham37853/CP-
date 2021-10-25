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


/*
 * Given a string you need to print the size of the longest possible substring that has exactly K unique characters.
 *  If there is no possible substring then print -1.
*/
int longestKSubstr(string s, int k) {
	int ans = -1;
	unordered_map<char, int> m; // for having k unique characters
	int i = 0;
	int j = 0;
	while (j < s.length()) {
		m[s[j]] += 1;
		if (m.size() < k) {
			j += 1;
		}
		else if (m.size() == k) {
			ans = max(ans, j - i + 1);
			j += 1;
		}
		else {
			while (m.size() > k) {
				m[s[i]] -= 1;
				if (m[s[i]] == 0) m.erase(s[i]);
				i += 1;
			}
			j += 1;
		}
	}
	return ans;
}

void test_case(){
	string s;
	int k;
	cin >> s;
	cin >> k;
	cout << longestKSubstr(s, k) << endl;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}
