#include<bits/stdc++.h> 
using namespace std;
const long long MAX = 1000 + 1;
long long  dp[MAX] = {-1};
const int MOD = 1e9 + 7;


// this is memoisation.
long long  fibo(long long n) {
	if (n == 0 || n == 1) return n;
	if (dp[n] != -1) return dp[n];
	long long prev = fibo(n - 1);
	long long prevPrev = fibo(n - 2);
	long long curr = (prev % MOD + prevPrev % MOD) % MOD;
	return dp[n] = curr;
}

// DT 038
// This is the recursive solution of 0-1 knapsack.

int knapsackRecurr(int index, vector<int> &values, vector<int> &weight, int W, vector<vector<int>> &dp) {
	if (index < 0 || W <= 0) return 0;
	int took  = 0, didNotTake = 0;
	if (dp[index][W] != -500) return dp[index][W];
	if (weight[index] <= W)
		took = knapsackRecurr(index - 1, values, weight, W - weight[index], dp) + values[index];
	didNotTake = knapsackRecurr(index - 1, values, weight, W, dp);
	return dp[index][W] = max(took, didNotTake);
}


int topDownKnapsack(vector<int> &values, vector<int> &weight, vector<vector<int>> &dp, int maxWeight) {
	int n = values.size();
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= maxWeight; j++) {
			if (i == 0 || j == 0) dp[i][j] = 0;
		}
	}
	for (int index = 1; index <= n; index++) { // 0 - n
		for (int W = 1; W <= maxWeight; W++) { // 0 - maxWeight
			int took  = 0, didNotTake = 0;
			if (weight[index - 1] <= W) {
				took = dp[index - 1][W - weight[index - 1]] + values[index - 1];
			}
			didNotTake = dp[index-1][W];
			dp[index][W] = max(took, didNotTake);
		}
	}
	// 0 - W -> j
	return dp[n][maxWeight];
}



// bottom up approach. -> for loop k through v hota hai
// memoisation.

// if the ans is large return modulo of 1e9 + 7 
// (a+b) % MOD = (a % MOD + b % MOD) % MOD
// series is of positive integers then we can initialise our dp with -1 or any other negative value.



int main() {
	memset(dp, -1, sizeof(dp));
	int n, W;
	cin >> n >> W;
	vector<int> weight(n), value(n);
	vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
	for (int i = 0; i < n; i++) {
		cin >> value[i];
		cin >> weight[i];
	}
	cout << topDownKnapsack(value, weight, dp, W) << endl;
	for (auto i : dp) {
		for (auto j : i) cout << j <<" "; 
	}
	return 0;
}