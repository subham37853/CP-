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

int findMaximumXOR(vector<int> &a) {
	int maxLength = 0;
	Trie trie;
	for (int i = 0; i < a.size(); i++) {
		trie.insert(a[i]);
	}
	for (int i : a) {
		maxLength = max(maxLength, trie.getMax(i));
	}
	return maxLength;
}

void test_case(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &i : a) cin >> i;
	cout << findMaximumXOR(a) << endl;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}
