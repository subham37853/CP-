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

vector<vector<int>> ans;

bool isValid(int N, int row, int col) {
    return row >= 0 && row < N && col >= 0 && col < N;
}

void dfs(vector<vector<int>> &maze, int row, int col, int N, vector<vector<int>> &visited) {
	if (isValid(N, row, col) == false || maze[row][col] == 0 || visited[row][col] == 1) return;
	if (row == N - 1 && col == N - 1) {
		vector<int> linearAns;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				linearAns.push_back(visited[i][j]);
			}
		}
		linearAns.back() = 1;
		ans.push_back(linearAns);
		return;
	}
	visited[row][col] = 1;
	dfs(maze, row + 1, col, N, visited);
	dfs(maze, row - 1, col, N, visited);
	dfs(maze, row, col + 1, N, visited);
	dfs(maze, row, col - 1, N, visited);
	visited[row][col] = 0;
}

vector<vector<int>> ratInAMaze(vector<vector<int> > &maze, int n){
	if (maze[0][0] == 0 || maze[n-1][n-1] == 0) return {};
	vector<vector<int>> visited(n, vector<int> (n, 0));
	dfs(maze, 0, 0, n, visited);
	return ans;
}

void test_case(){
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	for (auto &i : a) {
		for (auto &j : i) cin >> j;
	}
	auto ans = ratInAMaze(a, n);
	debug(ans);
}

int main() {
	int T = 1;
	// scanf("%d", &T);
	while(T--) {
		test_case();
	}
}
