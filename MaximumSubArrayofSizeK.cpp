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

// Given an array of size n find the maximum sum of a subarray of size K.

int findMaximumSubarray(vector<int> &a, int k) {
	int ans = INT_MIN;
	int sum = 0;
	for (int i = 0; i < k; i++) {
		sum += a[i];
	}
	ans = max (ans, sum);
	debug(sum);
	int prev = 0;
	for (int i = k; i < (int)a.size(); i++) {
		sum -= a[prev++];
		debug(sum);
		sum += a[i];
		debug(sum);
		ans = max(ans, sum);
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
	cout << findMaximumSubarray(a, k) << endl;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}
