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

// Given an array of non-negative integers, and a value sum, 
// determine if there is a subset of the given set with sum equal to given sum. 


// Recurrsive Approach, we have given two choices same as knapsack.
// 1. if the element is smaller than the left sum then either choose the element or not choose it
// 2. if the element is not smaller than the left sum then not choose it.
// The result will be the OR operation of these two choices as if any of the two is true then the final ans is true.

bool subSetSumRecurr(int n, vector<int> &a, int sum) {
	// Base condition where if we get the sum then its true
	if (sum == 0) return true;
	// Second base condition that the sum is not zero but we are out of bounds then return false
	if (n < 0) return false;
	// Now the two choices
	bool taken = false, notTaken = false;
	if (a[n] <= sum) {
		taken = subSetSumRecurr(n-1, a, sum - a[n]);
		notTaken = subSetSumRecurr(n-1, a, sum);
		return taken || notTaken;
	}
	return subSetSumRecurr(n-1, a, sum);
}

// Memoising the Recurrsive Solution Using A Memory Table.

bool subSetSumMemo(int n, vector<int> &a, int sum, vector<vector<bool>> &dp) {
	if (sum == 0) return true;
	if (n < 0) return false;
	// if the ans is already computed before and it is saved in the table the return the precomputed value
	if (dp[sum][n] != NULL) return dp[sum][n];
	// Now the two choices
	bool taken = false, notTaken = false;
	if (a[n] <= sum) {
		taken = subSetSumMemo(n-1, a, sum - a[n], dp);
		notTaken = subSetSumMemo(n-1, a, sum, dp);
		return dp[sum][n] = taken || notTaken;
	}
	return dp[sum][n] = subSetSumMemo(n-1, a, sum, dp);
}

// Using Top Down DP

bool subSetSumTopDown(int n, vector<int> a, int sum, vector<vector<bool>> &dp) {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (i == 0) dp[i][j] = false;
			if (j == 0) dp[i][j] = true;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (a[i-1] <= j) {
				dp[i][j] = dp[i-1][j-a[i-1]] || dp[i-1][j];
			}
			else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n][sum];
}

bool subSetSum(int n, vector<int> &a, int sum) {
	vector<vector<bool>> dp(n + 1, vector<bool>(sum+1, false));
	return subSetSumTopDown(n, a, sum, dp);
}

void test_case(){
	int n, sum;
	cin >> n;
	vector<int> a(n);
	for (auto &i : a) {
		cin >> i;
	}
	cin >> sum;
	bool ans = subSetSum(n, a, sum);
	debug(ans);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}
