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

int findUppar(vector<int> &a, int key) {
	int low = 0;
	int high = a.size();
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (a[mid] > key) high = mid - 1;
		else low = mid + 1;
	}
	return low;
}

int LIS(vector<int> &a) {
	int n = a.size();
	vector<int> res;
	for (int i = 0; i < n; i++) {
		if (i == 0 || a[i] > res.back()) {
			res.push_back(a[i]);
		} else {
			int index = findUppar(res, a[i]);
			res[index] = a[i];
		}
	}
	debug(res);
	return res.size();
}

void test_case(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &i : a) cin >> i;
	int ans = LIS(a);
	debug(ans);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}
