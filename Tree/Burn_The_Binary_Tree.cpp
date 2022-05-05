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

struct TreeNode {
	int  val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int _val) {
		val = _val;
		left = NULL;
		right = NULL;
	}
};

int burnTreeHelper(TreeNode* root, TreeNode* target, queue<TreeNode*> &q) {
	if (root == NULL) return 0;
	if (root == target) {
		cout << root->val << endl;
		if (root->left) q.push(root->left);
		if (root->right) q.push(root->right);
		return 1;
	}
	int a = burnTreeHelper(root->left, target, q);
	if (a == 1) {
		while (!q.empty()) {
			TreeNode* node = q.front();
			q.pop();
			cout << node->val << " ";
			if (node->left) q.push(node->left);
			if (node->right) q.push(node->right);
		}
		if (root->right) q.push(root->right);
		cout << root->val << endl;
		return 1;
	}
	int b = burnTreeHelper(root->right, target, q);
	if (b == 1) {
		while (!q.empty()) {
			TreeNode* node = q.front();
			q.pop();
			cout << node->val << " ";
			if (node->left) q.push(node->left);
			if (node->right) q.push(node->right);
		}
		if (root->left) q.push(root->right);
		cout << root->val << endl;
		return 1;
	}
	return 0;
}

void burnTree(TreeNode* root, TreeNode* target) {
	queue<TreeNode*> q;
	burnTreeHelper(root, target, q);
	while (!q.empty()) {
		int s = q.size();
		for (int i = 0; i < s; i++) {
			auto node = q.front();
			q.pop();
			cout << node->val << " ";
			if (node->left) q.push(node->left);
			if (node->right) q.push(node->right);
		}
		cout << endl;
	}
}

void test_case(){
	
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}
