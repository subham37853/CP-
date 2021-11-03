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

// Given an array containing N integers and an integer K.
// Your task is to find the length of the longest Sub-Array with the sum of the elements
// equal to the given value K.

// Note : This problem is of a Variable Sized Sliding Window that the sum is constant but we have to 
// Maximize the window size


// This logic only works for positive integers in the array 
int findLargestSubArray(vector<int> &a, int n, int k) {
	int ans = 0;
	int i = 0;
	int j = 0;
	int sum = 0;
	while (j < n) {
		sum += a[j];
		if (sum > k) {
			while (i < n && sum > k) sum -= a[i++];
		}
		else if (sum == k) {
			ans = max(ans, j - i + 1);
		}
		j += 1;
	}
	return ans;
}

// Universal Solution
int LargestSubArray(vector<int> &a, int n, int k) {
	int ans = 0;
	unordered_map<int, int> m;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		if (sum == k) {
			ans = i + 1;
		}
		if (m.find(sum) == m.end()) m[sum] = i;
		if (m.find(sum - k) != m.end()) ans = max(ans, i - m[sum-k]);
	}
	return ans;
}

void test_case(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &i : a) cin >> i;
	int k;
	cin >> k;
	int ans = LargestSubArray(a, a.size(), k);
	debug(ans);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}
