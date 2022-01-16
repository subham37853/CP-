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

// Question : https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

vector<vector<int>> dp;
int helper(vector<vector<int>> &points, int n, int index, int prev) {
    if (index == points.size()) return 0;
    if (dp[index][prev] != -1) return dp[index][prev];
    if (prev == 0) {
        return dp[index][prev] = max(points[index][1] + helper(points, n, index + 1, 1),
                   points[index][2] + helper(points, n, index + 1, 2));
    }
    else if (prev == 1) {
        return dp[index][prev] = max(points[index][0] + helper(points, n, index + 1, 0),
                   points[index][2] + helper(points, n, index + 1, 2));
    }
    else if (prev == 2) {
        return dp[index][prev] = max(points[index][0] + helper(points, n, index + 1, 0), 
                           points[index][1] + helper(points, n, index + 1, 1));
    }
    else {
	return dp[index][prev] = max({points[index][0] + helper(points, n, index + 1, 0), 
				points[index][1] + helper(points, n, index + 1, 1),
                points[index][2] + helper(points, n, index + 1, 2)});
    }
}


void test_case(){
	int n;
	cin >> n;
	pair<int, int> p;
	vector<vector<int>> points;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		points.push_back({a, b, c});
	}
	// for multiple test cases, clear the dp
	dp.clear();
	dp.resize(n + 1, vector<int>(4, -1));
	int ans = helper(points, n, 0, 3);
	cout << ans << endl;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}
