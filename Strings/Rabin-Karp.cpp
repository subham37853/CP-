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

const int NAX = 1e4 + 7;

int getCode(char c) {
	return int(c) - 96;
}

string solve(string &s, int length, vector<int> &power) {
	int curr = 0;
	unordered_set<int> set;
	for (int i = 0; i < length; i++) {
		curr = (curr * 26 + getCode(s[i])) % NAX;
	}
	debug(curr);
	int start = 0;
	set.insert(curr);
	for (int i = length; i < s.size(); i++) {
		// debug(curr);
		curr = curr % power[length - 1];
		curr = (((curr * 26) % NAX )+ getCode(s[i])) % NAX;
		start += 1;
		if (set.find(curr) != set.end()) {
			string currS = s.substr(start, length);
			return currS;
		}
		set.insert(curr);
	}
	return "";
}

void test_case(){
	string s;
	cin >> s;
	vector<int> power(s.size(), 1);
	for (int i = 1; i < s.size(); i++) {
		power[i] = (power[i-1] * 26) % NAX;
	}
	string ans = "";
	int low = 0, high = s.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        auto curr = solve(s, mid, power);
        if (curr.size() > ans.size()) ans = curr;
        if (curr.size() > 0) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    if (ans.size() == 0) cout << "NULL" << endl;
    else cout << ans << endl;
}

int main() {
	int T = 1;
	// scanf("%d", &T);
	while(T--) {
		test_case();
	}
}
