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

// Given an array of size n find the first negative integer in every window of size k.

vector<int> firstNegative(vector<int> &a, int k) {
	vector<long long> negatives;
	vector<long long> res;
	int n = a.size();
	int front = 0;
	for (int i = 0; i < k; i++) {
		if (a[i] < 0) negatives.push_back(a[i]);
	}
	debug(negatives);
	int prev = 0;
	if (negatives.size() == 0) res.push_back(0);
	else res.push_back(negatives[front]);
	int size = negatives.size();
	for (int i = k; i < n; i++) {
		if (a[prev++] < 0) {
			front += 1;
			size -= 1;
		}
		if (a[i] < 0) {
			negatives.push_back(a[i]);
			size += 1;
		}
		res.push_back((size == 0) ? 0 : negatives[front]);
	}
	return res;
}

void test_case(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &i : a) cin >> i;
	int k;
	cin >> k;
	firstNegative(a, k);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}
