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

// Here what i can do: 
// 1. I have two choices one to choose the element from the array 
// 2. Other not to choose the element from the array
// So i will write a recursive function with given choices.

int knapsackRecurr(int W, vector<int> &wt, vector<int> &val, int n) {
	// Base condition if all the elements are taken then return 
	if (n < 0) return 0;
	// Now the two choices to choose from 

	int taken = 0;
	if (wt[n] <= W) {
		taken = knapsackRecurr(W - wt[n], wt, val, n-1) + val[n];
	}
	int notTaken = knapsackRecurr(W, wt, val, n-1);
	return max(taken, notTaken);
}


// Memoising The Recurrsive Solution 

int knapsackMemo(int W, vector<int> &wt, vector<int> &val, int n, vector<vector<int>> &dp) {
	// Base condition if all the elements are taken then return 
	if (n < 0) return 0;
	// What if the value is already computed then it is saved in dp table 
	if (dp[W][n] != -1) return dp[W][n];
	// Now the two choices to choose from 
	int taken = 0, notTaken = 0;
	if (wt[n] <= W) {
		taken = knapsackMemo(W - wt[n], wt, val, n-1, dp) + val[n];
	}
	notTaken = knapsackMemo(W, wt, val, n-1, dp);
	dp[W][n] = max(taken, notTaken);
	return dp[W][n];
}

// Making a non Recursive Function that is Top Down DP

int knapsackTopDown(int W, vector<int> &wt, vector<int> &val, int size, vector<vector<int>> &dp) {
	dp[0][0] = 0;
	for (int i = 0; i <= W; i++) {
		dp[i][0] = 0;
	}
	for (int i = 0; i <= size; i++) {
		dp[0][i] = 0;
	}
	for (int w = 1; w <= W; w++) {
		for (int n = 1; n <= size; n++) {
			if (wt[n-1] <= w) {
				dp[w][n] = max(dp[w - wt[n-1]][n-1] + val[n-1], dp[w][n-1]);
			}
			else {
				dp[w][n] = max(dp[w][n], dp[w][n-1]);
			}
		}
	}
	return dp[W][size];
}

int knapsack(int W, vector<int> &wt, vector<int> &val, int n) {
	vector<vector<int>> dp(W + 1, vector<int> (n + 1, -1));
	return knapsackTopDown(W, wt, val, n, dp);
}

void test_case(){
	int n, w;
	cin >> n >> w;
	vector<int> wt(n), val(n);
	for (auto &i : wt) cin >> i;
	for (auto &i : val) cin >> i;
	int ans = knapsack(w, wt, val, n);
	debug(ans);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}
