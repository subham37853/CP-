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

/*

Given an array “A” of N integers and you have also defined the new array “B” as a concatenation of array “A” for an infinite number of times.
For example, if the given array “A” is [1,2,3] then, infinite array “B” is [1,2,3,1,2,3,1,2,3,.......].
Now you are given Q queries, each query consists of two integers “L“ and “R”. Your task is to find the sum of the subarray from index “L” to “R” (both inclusive) in the infinite array “B” for each query.

Sample Input:
1
3
1 2 3
2
1 3
1 5

Output:
6 9

*/


int SUM;
vector<int> prefix;

int findSum(int N, int R) {
	int count = (R / N);
	int res = (count * SUM);
	res += (prefix[R % N]);
	return res;
}

void test_case(){
	int N;
	cin >> N;
	vector<int> a(N);
	prefix.resize(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		SUM += a[i];
	}
	// Preprocessing starts from here
	prefix[0] = a[0];
	for (int i = 1; i < N; i++) {
		prefix[i] = prefix[i-1] + a[i];
	}
	int query;
	cin >> query;
	for (int i = 0; i < query; i++) {
		int L, R;
		cin >> L >> R;
		int RSum = findSum(N, R - 1);
		int LSum = findSum(N, L-2);
		int ans = RSum - LSum;
		cout << ans << endl;
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}
