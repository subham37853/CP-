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

// Program for merge sort algorithm

void merge(vector<int> &a, int low, int mid, int high) {
	int left = mid -low + 1;
	int right = high - mid;
	int k = low;
	vector<int> x(left);
	vector<int> y(right);
	for (int i = 0; i < left; i++) {
		x[i] = a[low + i];
	}
	for (int i = 0; i < right; i++) {
		y[i] = a[mid + i + 1];
	}
	int i = 0, j = 0;
	while (i < left && j < right) {
		if (x[i] <= y[j]) {
			a[k++] = x[i++]; 
		}
		else {
			a[k++] = y[j++];
		}
	}
	while (i < left) {
		a[k++] = x[i++];
	}
	while (j < right) {
		a[k++] = y[j++];
	}
}

void mergeSort(vector<int> &a, int low, int high) {
	if (low < high) {
		int mid = low + (high - low)/2;
		mergeSort(a, low, mid);
		mergeSort(a, mid + 1, high);
		merge(a, low, mid, high);
	}
}

void test_case(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &i : a) cin >> i;
	cout << "Before Sorting" << endl;
	debug(a);
	mergeSort(a, 0, n-1);
	cout << "After Sorting" << endl;--02
	debug(a);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}
