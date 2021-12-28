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

bool isValid(vector<vector<int>> &matrix, int digit, int row, int col) {
	for (int i = 0; i < 9; i++) {
		if (matrix[i][col] == digit) return false;
		if (matrix[row][i] == digit) return false;
		if (matrix[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == digit) return false;
	}
	return true;
}

bool solve(vector<vector<int>> &matrix) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (matrix[i][j] == 0) {
				for (int val = 1; val <= 9; val++) {
					if(isValid(matrix, val, i, j)) {
						matrix[i][j] = val;
						if (solve(matrix)) return true;
						else matrix[i][j] = 0;
					} 
				}
				return false;
			}
		}
	}
	return true;
}

bool isItSudoku(int m[9][9]) {
	vector<vector<int>> matrix(9, vector<int> (9, 0));
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			matrix[i][j] = m[i][j];
		}
	}
	debug(matrix);
	return solve(matrix);
}

void test_case(){
	int matrix[9][9];
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> matrix[i][j];
		}
	}
	bool ans = isItSudoku(matrix);
	debug(ans);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}
