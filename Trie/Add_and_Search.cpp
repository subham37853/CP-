#include <bits/stdc++.h>
#include <numeric>
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

const int MAX = 26;

class Node {
public:
	vector<Node*> links;
	bool isEnd;
public:
	Node() {
		links.resize(MAX, NULL);
		isEnd = false;
	}
	
	bool contains(int index) {
		return links[index] != NULL;
	}
	
	void put(int index) {
		links[index] = new Node();
	}
	
	Node* get(int index) {
		return links[index];
	}
};

class Trie {
public:
	Node* root;
public:
	Trie() {
		root = new Node();
	}
	
	void insert(string &word) {
		Node* node = root;
		for (char &i : word) {
			int index = i - 'a';
			if (!node->contains(index)) {
				node->put(index);
			}
			node = node->get(index);
		}
		node->isEnd = true;
	}
	
	bool searchWord(string &word, Node* node, int index) {
		for (int i = index; i < word.size(); i++) {
			if (word[i] != '.') {
				if (node->contains(i)) node = node->get(i);
				else return false;
			}
			else {
				Node* temp = node;
				for (int j = 0; j < MAX; j++) {
					if (temp->contains(j)) {
						node = temp->get(j);
						if (searchWord(word, node, i)) return true;
					}
				}
			}
		}
		return node && node->isEnd;
	}
	
};

class WordDictionary
{
private:
	Trie trie;
public:
	WordDictionary() {
	}
	
	void addWord(string &word) {
		trie.insert(word);
	}
	
	bool search(string &word) {
		return trie.searchWord(word, trie.root, 0);
	}
};

int32_t main() {
	WordDictionary wordDictionary;
	
	return 0;
}