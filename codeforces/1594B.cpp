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
#define MOD (ll)(1e9+7)
ll add (ll a, ll b) {
	return ((a % MOD) + (b % MOD)) % MOD;
}
ll sub(ll a, ll b) {
	return ((a % MOD) - (b % MOD)) % MOD;
}
ll multi(ll a, ll b) {
	return ((a % MOD) * (b % MOD)) % MOD;
}
ll fpow(ll x, ll y) {
	ll res = 1;
    x = x % MOD; 
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1LL) 
        	res = (res*x) % MOD;
        y = y>>1LL;
        x = (x*x) % MOD;
    }
    return res;
}


void test_case(){
	ll n, k;
	cin >> n >> k;
	ll ans = 0;
	ll p = 0;
	while (k) {
		if (k & 1) 
			ans = add(ans, fpow(n, p));
		k >>= 1;
		p += 1;
	}
	cout << ans << endl;
}

int main() {
	ll T;
	cin >> T;
	while(T--) {
		test_case();
	}
}
