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
Given an integer array arr of size N, the task is to divide it into two 
sets S1 and S2 such that the absolute difference between their sums is 
minimum and find the minimum difference
------------------------------------------------------------------------
this question is also similar two the subset sum.

Thinking Process: 
-----------------
What we know is we have to divide the array into two parts such that their 
two subsets will have the minimum sum difference.

Lets say sum of one set is S1 and other is S2,
Goal is to minimise (S1 - S2) or (S2 - S1)
What we know is,
The minimum difference can be as low as 0. 
The maximum difference can be as high as sum of the array.
So this can be our range to find the sum which is in between these ranges.
Range is : 0 to S (S being the sum of the array) 

Lets suppose that S1 will always be smaller (cause have to find the smaller set)
then S2 will be, S2 = S - S1
so the problem statement becomes =  minimise(S2 - S1) 
								 => minimise(S - S1 - S1) 
								 => minimise(S - 2*S1)
*/


int subsetSumDifference(vector<int> &a) {
	int n = a.size();
	int ans = INT_MAX;
	int S = accumulate(a.begin(), a.end(), 0);
	// Now we have to find the subset whose sum will be S/2. 
	vector<vector<int>> dp(n + 1, vector<int>(S/2 + 1, 0));
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= S/2; j++) {
			if (i == 0) dp[i][j] = 0;
			if (j == 0) dp[i][j] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= S/2; j++) {
			if (a[i-1] <= j) {
				dp[i][j] = dp[i-1][j] || dp[i-1][j - a[i-1]];
			}
			else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	// Now filter out the values which can give us a sum whose subset exists
	vector<int> filter;
	for (int i = 0; i <= S/2; i++) {
		if (dp[n][i] == 1) filter.push_back(i);
	}
	debug(filter);
	// Minimise the ans using the formula we created min(S - 2*S1)
	for (int i = 0; i < filter.size(); i++) {
		ans = min(ans, S - 2*filter[i]);
	}
	return ans;
}

void test_case(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &i : a) cin >> i;
	int ans = subsetSumDifference(a);
	debug(ans);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}
