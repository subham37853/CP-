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

int n;
vector<int> a(n);

int merge(int low, int mid, int high) {
	int count = 0;
	int j = mid + 1;
	
	for (int i = low; i <= mid; i++) {
		while (j <= high && a[i] > a[j]) j++;
		count += (j - (mid + 1));
	}
	
	vector<int> temp;
	int i = low; 
	j = mid + 1;
	
	while (i <= mid && j <= high) {
		if (a[i] <= a[j]) {
			temp.push_back(a[i++]);
		}
		else {
			temp.push_back(a[j++]);
		}
	}
	while (i <= mid) {
		temp.push_back(a[i++]);
	}
	while (j <= high) {
		temp.push_back(a[j++]);
	}
	for (int rep = low; rep <= high; ++rep) {
		a[rep] = temp[rep - low];
	}
	return count;
}

int helper(int low, int high) {
	if (low >= high) return 0;
	
	int mid = low + (high - low)/2;
	int ans = helper(low, mid);
	ans += helper(mid + 1, high);
	ans += merge(low, mid, high); 
	return ans;
}

void test_case(){
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i;
	debug(n, a);
	int ans = helper(0, n-1);
	debug(ans);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}
