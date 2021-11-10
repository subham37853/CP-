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
Given an array arr[] of size N, check if it can be partitioned into two parts
such that the sum of elements in both parts is the same.
*/

// it is the same problem as the subset sum. 
// What we have to do is find the sum of the given array
// and the divide it two half (only if the sum is even) 
// then find if the sum can be formed by the array elements 

bool equalSum(vector<int> &a, int n) {
	int sum = accumulate(a.begin(), a.end(), 0);
	if (sum % 2 == 1) return false;
	sum = sum / 2;
	vector<vector<bool>> dp(sum + 1, vector<bool>(n + 1, false));
	for (int i = 0; i < sum + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			if (j == 0) {
				dp[i][j] = false;
			}
			if (i == 0) {
				dp[i][j] = true;
			}
		}
	}
	for (int i = 1; i <= sum; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[j-1] <= i) {
				dp[i][j] = max(dp[i - a[j-1]][j-1], dp[i][j-1]);
			}
			else {
				dp[i][j] = dp[i][j-1];
			}
		}
	}
	return dp[sum][n];
}

void test_case(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &i : a) cin >> i;
	bool ans = equalSum(a, n);
	debug(ans);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}
