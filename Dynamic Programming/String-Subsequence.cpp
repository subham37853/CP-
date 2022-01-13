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

int helper(int s_index, int p_index, string &s, string &p, vector<vector<int>> &dp) {
	if (p_index == p.size()) return 1;
	if (s_index == s.size()) return 0;
	if (dp[s_index][p_index] != -1) return dp[s_index][p_index];
	if (s[s_index] == p[p_index]) {
		int taken = helper(s_index + 1, p_index + 1, s, p, dp);
		int notTaken = helper(s_index + 1, p_index, s, p, dp);
		return dp[s_index][p_index] = taken + notTaken;
	}
	else return dp[s_index][p_index] =  helper(s_index + 1, p_index, s, p, dp);
}

void test_case(){
	string s;
	string p;
	cin >> s >> p;
	vector<vector<int>> dp(s.size() + 1, vector<int> (p.size() + 1, -1));
	cout << helper(0, 0, s, p, dp) << endl;
}

int main() {
	int T = 1;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}
