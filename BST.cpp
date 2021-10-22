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

// This is the implementation of the Binary Search Tree

struct Node {
	int data;
	struct Node *left;
	struct Node *right;
	Node(int val) {
		data = val;
		left = NULL;
		right = NULL;
	}
};

// Method to create a node in BST.
void insertNode(int val, Node* &root) {
	if (root == NULL) {
		root = new Node(val);
		return;
	}
	if (val > root->data) {
		insertNode(val, root->right);
	}
	else insertNode(val, root->left);
}

// Method for printing the node in inorder traversal.
void printBST(Node* &root) {
	if (root == NULL) return;
	printBST(root->left);
	cout << root->data << " ";
	printBST(root->right);
}

// Method for forming a Binary Search Tree using a sorted array.
Node* ArrayToBST(vector<int> a) {
	if (a.size() == 0) return NULL;
	if (a.size() == 1) return new Node(a[0]);
	int mid = a.size() / 2;
	Node* root = new Node(a[mid]);
	root->left = ArrayToBST({a.begin(), a.begin() + mid});
	root->right = ArrayToBST({a.begin() + mid + 1, a.end()});
	return root;
}

// Find the Kth Smallest Element in a BST

Node* findKthSmallest(Node* root, int &k) {
	if (root == NULL) return NULL;
	Node* left = findKthSmallest(root->left, k);
	if (left != NULL) return left;
	k -= 1;
	if (k == 0) return root;
	return findKthSmallest(root->right, k);
}

// Method to check whether a given tree is BST or not
// Prev is a node to keep track of the parent.
bool checkBST(Node* root, Node* &prev) {
	if (root == NULL) return true;
	if (checkBST(root->left, prev) == false) return false;
	if (prev != NULL && prev->data >= root->data) return false;
	prev = root;
	return checkBST(root->right, prev);
}

int main() {
	vector<int> a{-10,-3,0,5,9};
	Node *root = ArrayToBST(a);
	printBST(root);
}
