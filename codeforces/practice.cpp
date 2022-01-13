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



// int helper(string &s, int n, int start, int end, int index, int currPosi) {
// 	if (index == s.size()) {
// 		return 0;
// 	}
// 	if (dp[index][currPosi] != -1) {
// 		return dp[index][currPosi];
// 	}
// 	if(currPosi == end) {
// 		if (index < s.size()) {
// 			if (s[index] == 'l') 
// 				return dp[index][currPosi] = 1 + helper(s, n, start, end, index + 1, currPosi - 1);
// 			else 
// 				return dp[index][currPosi] = 1 + helper(s, n, start, end, index + 1, currPosi + 1);
// 		}
// 	}
// 	int ans = 0;
// 	if (s[index] == 'l') {
// 		if (currPosi > 0) {
// 			ans += helper(s, n, start, end, index + 1, currPosi - 1);
// 			ans += helper(s, n, start, end, index + 1, currPosi);
// 		}
// 		else {
// 			ans += helper(s, n, start, end, index + 1, currPosi);
// 		}
// 	}
// 	else {
// 		if (currPosi + 1 < n) {
// 			ans += helper(s, n, start, end, index + 1, currPosi + 1);
// 			ans += helper(s, n, start, end, index + 1, currPosi);
// 		}
// 		else {
// 			ans += helper(s, n, start, end, index + 1, currPosi);
// 		}
// 	}
// 	return dp[index][currPosi] = ans;
// }

int schedule(vector<int> &start, vector<int> &end, vector<int> &profit) {
	int n = start.size();
	vector<vector<int>> jobs(n, vector<int> (3, 0));
	for (int i = 0; i < n; i++) {
		jobs[i] = {end[i], start[i], profit[i]};
	}
	sort(jobs.begin(), jobs.end());
	map<int, int> m;
	m[0] = 0;
	for (vector<int> &job : jobs) {
		int curr = prev(m.upper_bound(job[1]))->second + job[2];
		if (curr > m.rbegin()->second) {
			m[job[0]] = curr;
		}
	}
	return m.rbegin()->second;
}

int dp[1001][1001][2];

int bobAndApples(int index, vector<int> &vitamin, vector<int> &price, int M, int halfed) {
	if (index >= vitamin.size() || M <= 0) return 0;
	if (dp[index][M][halfed] != -1) return dp[index][M][halfed];
	if (halfed == 1) {
		if (price[index] <= M) {
			int taken = vitamin[index] + bobAndApples(index + 1, vitamin, price, M - price[index], halfed);
			int notTaken = bobAndApples(index + 1, vitamin, price, M, halfed);
			return dp[index][M][halfed] = max(taken, notTaken);
		}
		else {
			return dp[index][M][halfed] = bobAndApples(index + 1, vitamin, price, M, halfed);
		}
	}
	else if (price[index] <= M) {
		int taken = vitamin[index] + bobAndApples(index + 1, vitamin, price, M - price[index], 0);
		int halfedTaken = vitamin[index] +  bobAndApples(index + 1, vitamin, price, M - (price[index] / 2), 1);
		int notTaken = bobAndApples(index + 1, vitamin, price, M, 0);
		return dp[index][M][halfed] = max({taken, halfedTaken, notTaken});
	}
	else if (price[index] / 2 <= M && halfed == false) {
		int halfedTaken = vitamin[index] +  bobAndApples(index + 1, vitamin, price, M - (price[index] / 2), 1);
		int notTaken = bobAndApples(index + 1, vitamin, price, M, 0);
		return dp[index][M][halfed] = max(halfedTaken, notTaken);
	}
	else {
		return dp[index][M][halfed] = bobAndApples(index + 1, vitamin, price, M, 0);
	}
}

int makeSmallestNumber(int num) {
    int freq[10] = {0};
    bool is_pos = (num>0);
    num = abs(num);
    while (num) {
        int d = num % 10;
        freq[d]++;
        num = num / 10;
    }
    int result = 0;
    if(is_pos) {
      for (int i = 1 ; i <= 9 ; i++) {
          if (freq[i]) {
              result = i;
              freq[i]--;
              break;
          }
      }
      for (int i = 0 ; i <= 9 ; i++)
          while (freq[i]--)
              result = result * 10 + i;
    }
    else {
      for (int i = 9 ; i >= 1 ; i--) {
         if (freq[i]) {
            result = i;
            freq[i]--;
            break;
         }
      }
      for (int i = 9 ; i >=0 ; i--)
         while (freq[i]--)
            result = result * 10 + i;
      result = -result;
    }
    return result;
}

vector<int> alternateSort(vector<int> arr) {
	sort(arr.begin(), arr.end());
	vector<int> ans;
	for (int i = 0; i < arr.size(); i += 2) {
		ans.push_back(arr[i]);
	}
	return ans;
}

void test_case(){
	cout << makeSmallestNumber(310);
	vector<int> arr = {3, 5, 1, 5, 9, 10, 2, 6};
	auto ans = alternateSort(arr);
	debug(ans);
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
