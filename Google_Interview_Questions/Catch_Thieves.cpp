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
const int MOD = 1e9 + 7;
int add (int a, int b) { return ((a % MOD) + (b % MOD)) % MOD; }
int sub(int a, int b) { return ((a % MOD) - (b % MOD)) % MOD; }
int multi(int a, int b) { return ((a % MOD) * (b % MOD)) % MOD; }
int fpow(int x, int y) {
	int res = 1;
    x = x % MOD; 
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1) res = (res*x) % MOD;
        y = y>>1;
        x = (x*x) % MOD;
    }
    return res;
}

int catchThieves(vector<char> &a, int k) {
	vector<int> polices;
	vector<int> thieves;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == 'P') {
			polices.push_back(i);
		}
		else thieves.push_back(i);
	}
	int n = polices.size(), m = thieves.size();
	int i = 0, j = 0;
	int ans = 0;
	while (i < n && j < m) {
		if (abs(polices[i] - thieves[j]) <= k) ans++, i++, j++;
		else {
			if (polices[i] <= thieves[j]) i += 1;
			else j += 1;
		}
	}
	return ans;
}

void test_case(){
	int n, k;
	cin >> n >> k;
	vector<vector<char>> a(n, vector<char>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) 
			cin >> a[i][j];
	int ans = 0;
	for (auto &i : a) {
		ans += catchThieves(i, k);
	}
	cout << ans << endl;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}
