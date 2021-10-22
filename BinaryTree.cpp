#include<bits/stdc++.h>
using namespace std;

struct Node {
	int  data;
	struct Node *left;
	struct Node *right;
	Node(int val) {
		data = val;
		left = NULL;
		right = NULL;
	}
};

// This insertNode method is for creating a complete binary tree
void insertNode(int val, Node* &root) {
	if (root == NULL) {
		root = new Node(val);
		return;
	}
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		auto node = q.front();
		q.pop();
		if (node->left == NULL) {
			node->left = new Node(val);
			break;
		}
		else if (node->right == NULL) {
			node->right = new Node(val);
			break;
		}
		else {
			q.push(node->left);
			q.push(node->right);
		}
	}
}

// This method is for printing the left view of the binary tree
void leftView(Node *root, int level, int &maxLevel) {
	if (root == NULL) return;
	if (maxLevel < level) {
		cout << root->data << " ";
		maxLevel = level;
	}
	leftView(root->left, level + 1, maxLevel);
	leftView(root->left, level + 1, maxLevel);
}

// Bottom View of a Binary Tree
void bottomView(Node* root) {
	if (root == NULL) return;
	map<int, Node*> m;
	queue<pair<Node*, int>> q;
	q.push({root, 0});
	while (!q.empty()) {
		int hd = q.front().second;
		Node* node = q.front().first;
		m[hd] = node;
		if (node->left) q.push({node->left, hd-1});
		if (node->right) q.push({node->right, hd+1});
		q.pop();
	}
	for (auto i : m) {
		cout << i.second->data << " ";
	}
}

// Method to find the lowest common ascestor of two nodes
Node* findAncestors(Node* root, Node* p, Node* q) {
	if (root == NULL) return NULL;
	if (root == p || root == q) return root;
	Node* left = findAncestors(root->left, p, q);
	Node* right = findAncestors(root->right, p, q);
	if (left != NULL && right != NULL) return root;
	return (left == NULL) ? right : left;
}

void printBinaryTree(Node *root) {
	if (root == NULL) return;
	printBinaryTree(root->left);
	cout << root->data << " ";
	printBinaryTree(root->right);
}

int main() {
	int n;
	cin >> n;
	Node *root = NULL;
	for (int i = 0; i < n; i++) {
		int ele;
		cin >> ele;
		insertNode(ele, root);
	}
	bottomView(root);
	return 0;
}
