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

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(NULL), right(NULL) {}
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Node {
	int val;
	Node* next;
};

int findLengthOfLinkedList(Node* head) {
	int length = 0;
	while (head != NULL) head = head->next, length++;
	return length;
}

Node* reverseLinkedList(Node* node, Node* &head) {
    if (node == NULL)
        return NULL;
    if (node->next == NULL) {
        head = node;
        return node;
    }
    Node* node1 = reverseLinkedList(node->next, head);
    node1->next = node;
    node->next = NULL;
    return node;
}

Node* waveSort(Node* head) {
	if (head == NULL || head->next == NULL) return head;
	int n = findLengthOfLinkedList(head);
	Node* prev = NULL;
	Node* curr = head;
	int i = 0;

	while (i < n) {
		if (i % 2 == 0) {
			if (i > 0 && (prev->val) > (curr->val)) 
				swap((curr->val), (prev->val));
			if (i < n - 1 && curr->val < curr->next->val) 
				swap((curr->val), (curr->next->val));
		}
		i += 1;
		prev = curr;
		curr = curr->next;
	}
	return head;
}

int minJump(vector<int> &a) {
	int n = a.size();
	if (n == 1) return 0;
	int curr = a[0], canReach = 0, jumps = 1;
	for (int i = 1; i < n - 1; i++) {
		canReach = max(canReach, a[i] + i);
		if (i == curr) {
			jumps += 1;
			curr = canReach;
		}
	}
	return jumps;
}

// program to find how many AP series are there in a binary tree

bool checkIfAP(vector<int> &a) {
	if (a.size() == 1) return true;
	int commondiff = a[1] - a[0];
	for (int i = 2; i < a.size(); i++) {
		if (a[i] - a[i-1] != commondiff) return false;
	}
	return true;
}

int helper(TreeNode* root, vector<int> a) {
	if (root == NULL) return 0;
	a.push_back(root->val);
	if (root->left == NULL && root->right == NULL && checkIfAP(a)) {
		return 1;
	} 
	return helper(root->left, a) + helper(root->right, a);
}

int countAP(TreeNode* root) {
	vector<int> A;
	return helper(root, A);
}

TreeNode* trimBST(TreeNode* root, int low, int high) {
	if (root == NULL) return root;
	// if outside of range
	if (root->val < low) return trimBST(root->right, low, high);
	if (root->val > high) return trimBST(root->left, low, high);
	root->left = trimBST(root->left, low, high);
	root->right = trimBST(root->right, low, high);
	return root;
}

void reArrangeArray(vector<int> &a, int &k) {
	int n = a.size();
	int end = n - 1;
	int high = n-1;
	int low = 0;
	int curr = 0;
	while (curr <= high) {
		if (a[curr] < k) {
			swap(a[low++], a[curr++]);
		}
		else if (a[curr] > k) {
			swap(a[high--], a[curr]);
		}
		else {
			swap(a[curr], a[end--]);
			if (high == end + 1) high--;
		}
		debug(a);
	}
	for (int i : a) cout << i << " ";
	cout << endl;
}

int multiplyTwoNumberWithBitwise(int a, int b) {
	int res = 0;
	while (b > 0) {
		if (b % 2 == 1) {
			res += a;
		}
		a = a << 1; // this is doubling the number 
		b = b >> 1; // this is halfing the number
	}
	return res;
}

// given an array find the only duplicate number present in the array
int findDuplicate(vector<int>& a) {
	// the idea here is to use quick sort
	int slow = a[0];
	int fast = a[a[0]];
	while (slow != fast) {
		slow = a[slow];
		fast = a[a[fast]];
	}
	fast = 0;
	while (slow != fast) {
		slow = a[slow];
		fast = a[fast];
	}
	return slow;
}

void sortColors(vector<int>& nums) {
	int n = nums.size();
	int low = 0, mid = 0, high = n - 1;
	while (mid <= high) {
		if (nums[mid] == 0) {
			swap(nums[low++], nums[mid++]);
		} else if (nums[mid] == 2) {
			swap(nums[mid], nums[high--]);
		} else {
			mid++;
		}
	}
}

int missingNumber(vector<int>& a) {
	int sum = accumulate(begin(a), end(a), 0);
	int total = (a.size() * (a.size() + 1))/2;
	return total - sum;
}

int nextGap(int n) {
	if (n <= 1) return 0;
	return (int) n / 2 + (n % 2);
}

void mergeTwoArrays(vector<int> &a, vector<int> b) {
	int N = a.size();
	int M = b.size();
	int gap = N + M;
	int i, j;
	for (gap = nextGap(gap); gap > 0; gap = nextGap(gap)) {
		for (int i = 0; i + gap < N; i++)
			if (a[i] > a[i + gap]) swap(a[i], a[i + gap]);
		for (j = (gap > N) ? gap - N : 0; i < N && j < M; i++, j++) 
			if (a[i] > b[j]) swap(a[i], b[j]);
		if (j < M) 
			for (int j = 0; j + gap < M; j++) 
				if (b[j] > b[j + gap]) swap(b[j], b[j + gap]);
	}
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
	int N = intervals.size();
	sort(begin(intervals), end(intervals), [&] (const vector<int> &a, const vector<int> &b) {
		return a[0] < b[0];
	});
	vector<vector<int>> res;
	for (int i = 0; i < N; i++) {
		if (res.empty() || res.back()[1] < intervals[i][0]) res.push_back(intervals[i]);
		else {
			res.back()[0] = min(res.back()[0], intervals[i][0]);
			res.back()[1] = max(res.back()[1], intervals[i][1]);
		}
	}
	return res;
}

void rotate(vector<vector<int>>& matrix) {
	int N = matrix.size();
	int M = matrix[0].size();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			swap(matrix[i][j], matrix[j][i]);
		}
	}
	for (auto &i : matrix) {
		reverse(begin(i), end(i));
	}
}

void setZeroes(vector<vector<int>>& matrix) {
	int N = matrix.size();
	int M = matrix[0].size();
	bool colHasZero = false;
	for (int i = 0; i < N; i++) {
		if (matrix[i][0] == 0) colHasZero = true;
		for (int j = 1; j < M; j++) {
			if (matrix[i][j] == 0) {
				matrix[i][0] = matrix[0][j] = 0;
			}
		}
	}
	for (int i = N - 1; i >= 0; i--) {
		for (int j = M - 1; j >= 1; j--) {
			if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
		}
		if (colHasZero) matrix[i][0] = 0;
	}
}

int merge(vector<int> &a, int low, int mid, int high) {
	int count = 0;
	int i = low;
	int j = mid + 1;
	for (; i <= mid; i++) {
		while (j <= high && a[i] > 2 * a[j] * 1LL) j++;
		count += (j - mid - 1);
	}
	int left = low;
	int right = mid + 1;
	vector<int> temp;
	while (left <= mid && right <= high) {
		if (a[left] < a[right]) {
			temp.push_back(a[left++]);
		}
		else temp.push_back(a[right++]);
	}
	while (left <= mid) {
		temp.push_back(a[left++]);
	}
	while (right <= high) {
		temp.push_back(a[right++]);
	}
	for (int i = low; i <= high; i++) {
		a[i] = temp[i - low];
	}
	return count;
}

int divide(vector<int> &a, int low, int high) {
	if (low >= high) return 0;
	int mid = low + (high - low) / 2;
	int ans = divide(a, low, mid);
	ans += divide(a, mid + 1, high);
	ans += merge(a, low, mid, high);
	return ans;
}

int reversePairs(vector<int>& nums) {
	int n = nums.size();
	return divide(nums, 0, n - 1);
}

void nextPermutation(vector<int>& a) {
	int n = a.size();
	int i = 0;
	for (i = n - 2; i >= 0; i--) {
		if (a[i + 1] > a[i]) break;
	}
	if (i < 0) {
		reverse(begin(a), end(a));
		return;
	}
	int j = 0;
	for (j = n - 1; j > i; j++) {
		if (a[j] > a[i]) break;
	}
	swap(a[j], a[i]);
	reverse(a.begin() + i + 1, a.end());
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int N = matrix.size(), M = matrix[0].size();
	int low = 0;
	int high = (N * M) - 1;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (matrix[mid / M][mid % M] == target) return true;
		else if (matrix[mid / M][mid % M] > target) high = mid - 1;
		else low = mid + 1;
	}
	return false;
}

int majorityElement(vector<int>& nums) {
    int count = 1;
    int ans = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (count == 0) ans = nums[i];
        if (ans == nums[i]) count += 1;
        else count -= 1;
    }
    return ans;
}

int subarraySum(vector<int>& nums, int k) {
	int n = nums.size();
	int sum = 0;
	int ans = 0;
	unordered_map<int, int> m;
	m[0] = 1;
	for (int &i : nums) {
		sum += i;
		if (m.find(sum - k) != m.end()) ans += m[sum - k];
		m[sum] += 1;
	}
	return ans;
}

int findElementThatIsInItsCorrectPosition(vector<int> &a) {
	int low = 0, high = a.size() - 1;
	while (low <= high) {
		int mid = (high - low) / 2;
		if (a[mid] == mid) return mid;
		else if (a[mid] < mid) low = mid + 1;
		else high = mid - 1;
	}
	return -1;
}


// Dice throw with D number of dices F number of faces and find the number of combinations with sum S;
int helper(int D, int F, int S, vector<vector<int>> &dp) {
	if (D == 0) {
		if (S == 0) return 1;
		return 0;
	}
	if (dp[D][S] != -1) return dp[D][S];
	if (S < 0 || D > S) return 0;
	int val = 0;
	for (int i = 1; i <= F; i++) {
		val += helper(D - 1, F, S - i, dp);
	}
	return dp[D][S] = val;
}

int combination1(int D, int F, int S) {
	vector<vector<int>> dp(D + 1, vector<int> (S + 1, -1));
	return helper(D, F, S, dp);
}

void test_case(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &i : a) cin >> i;
	cout << findDuplicate(a) << endl;
}

int32_t main() {
	int D = 3, F = 3, S = 3;
	int ans =  combination1(D, F, S);
	cout << ans << endl;
}

