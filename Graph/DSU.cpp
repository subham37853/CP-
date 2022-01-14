#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define endl "\n"
#define PI 3.141592653589793238462
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

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

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll multiply(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll subtract(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll divide(ll a, ll b, ll m) {a = a % m; b = b % m; return (multiply(a, mminvprime(b, m), m) + m) % m;}  //only for prime m

class DSU {
private:
	vector<int> parent, size;
public:
	DSU(int n) {
		parent.resize(n);
		iota(parent.begin(), parent.end(), 0);
		size.resize(n, 0);
	}
	int findParent(int node) {
		if (parent[node] == node) return node;
		return parent[node] = findParent(parent[node]);
	}
	void doUnion(int x, int y) {
		int parentX = findParent(x);
		int parentY = findParent(y);
		if (parentX == parentY) return;
		if (size[parentX] < size[parentY]) {
			parent[parentX] = parentY;
			size[parentX] += size[parentY];
		}
		else {
			parent[parentY] = parentX;
			size[parentY] += size[parentX];
		}
		return;
	}
};


void test_case(){
	
}

int32_t main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int T;
	cin >> T;
	while(T--) {
		test_case();
	}
	return 0;
}



