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

class Node {
private:
	vector<Node*> link;
	
public:
	Node() {
		link.resize(2, NULL);
	}
	
	bool contains(int bit) {
		return link[bit] != NULL;
	}

	void put(int bit) {
		link[bit] = new Node();
	}
	
	Node* get(int bit) {
		return link[bit];
	}
	
};

class Trie {
private:
	Node* root;
	
public:
	Trie() {
		root = new Node();
	}
	
	void insert(int n) {
		Node* node = root;
		for (int i = 31; i >= 0; i--) {
			int bit = (n >> i) & 1;
			if (node->contains(bit) == false) {
				node->put(bit);
			}
			node = node->get(bit);
		}
	} 
	int getMax(int n) {
		Node* node = root;
		int ans = 0;
		for (int i = 31; i >= 0; i--) {
			int bit = (n >> i) & 1;
			if (node->contains(!bit)) {
				ans |= (1 << i); 
				node = node->get(!bit);
			}
			else {
				node = node->get(bit);
			}
		}
		return ans;
	}
};

vector<int> maximizeXor(vector<int>& a, vector<vector<int>>& queries) {
	int index = 0, n = a.size(), m = queries.size();
	vector<int> ans(m, 0);
	Trie trie;
	vector<vector<int>> q;
	
	for (int i = 0; i < m; i++) {
		q.push_back({queries[i][0], queries[i][1], i});
	}
	
	sort(q.begin(), q.end(), [&] (const vector<int> &a, const vector<int> &b) {
		return a[1] < b[1];	
	});
	sort(a.begin(), a.end());
	
	for (int i = 0; i < m; i++) {
		int ansIndex = q[i][2];
		int limit = q[i][1];
		int val = q[i][0]; // this is the value that we need to XOR with all the other elements or the array that are lesser than "limit"
		
		while (index < n && a[index] <= limit) {
			trie.insert(a[index]);
			index += 1;
		}
		
		if (index == 0) ans[ansIndex] = -1;
		else ans[ansIndex] = trie.getMax(val);
	}
	return ans;
}

void test_case(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int m;
	cin >> m;
	vector<vector<int>> queries(m, vector<int> (2));
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		queries[i] = {a, b};
	}
	auto ans = maximizeXor(a, queries);
	debug(ans);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}
