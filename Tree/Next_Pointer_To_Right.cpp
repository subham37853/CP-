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

struct Node {
	int  data;
	struct Node *left;
	struct Node *right;
	struct Node *next;
	Node(int val) {
		data = val;
		left = NULL;
		right = NULL;
		next = NULL;
	}
};

void insertNode(int val, Node* &root) {
	if (root == NULL) {
		root = new Node(val);
		return;
	}
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		// For debuggin the queue
		vector<Node*> list;
		int s = q.size();
		for (int i = 0; i < s; i++) {
			list.push_back(q.front());
			q.pop();
			q.push(list.back());
		}
		for (auto i : list) {
			if (i == NULL) cout << "NULL" << " ";
			else cout << i->data << " ";
		}
		cout << endl;
		// End of debugging 
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

Node* connect(Node* root) {
	if (root == NULL) return NULL;
	queue<Node*> q;
	q.push(root);
	q.push(NULL); // Why this ??
	while(!q.empty()) {
		//debug(q);
		Node* top1 = q.front();
		q.pop();
		Node* top2 = q.front();
		if(top1 == NULL) {
			q.push(NULL);
		}
		else {
			top1->next = top2;
			if(top1->left != NULL) {
				q.push(top1->left);
			}
			if(top1->right != NULL) {
				q.push(top1->right);
			}
		}
	}
	return root;
}

void test_case(){
	Node *root = NULL;
	for (int i = 0; i < 10; i++) {
		insertNode(i + 1, root);
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}
