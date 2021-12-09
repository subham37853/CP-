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

// Program to create a MaxHeap

class MaxHeap {
	public: 
		int *a;
		int size;
		int capacity;
		
		MaxHeap(int s) {
			size = 0;
			a = new int[s];
			capacity = s;
		}
		
		int left(int i) {
			return (2*i + 1);
		}
		
		int right(int i) {
			return (2*i + 2);
		}
		
		int parent(int i) {
			return (i-1)/2;
		}
		
		void insert(int val) {
			if (size == capacity) {
				cout << "Can not be inserted due to overflow" << endl;
				return;
			}
			size += 1;
			a[size - 1] = val;
			for (int i = size - 1; i != 0 && a[i] > a[parent(i)];) {
				swap(a[i], a[parent(i)]);
				i = parent(i);
			}
		}
		
		void maxHeapify(int i) {
			int l = left(i);
			int r = right(i);
			int biggest = i;
			if (l < size && a[l] > a[biggest]) biggest = l;
			if (r < size && a[r] > a[biggest]) biggest = r;
			if (biggest != i) {
				swap(a[biggest], a[i]);
				maxHeapify(biggest);
			}
		}
		
		int getMax() {
			if (size == 0) return INT_MAX;
			return a[0];
		}
		
		int extractMax() {
			if (size == 0) return INT_MAX;
			if (size == 1) {
				size -= 1;
				return a[0];
			}
			swap(a[0], a[size-1]);
			size -= 1;
			maxHeapify(0);
			return a[size];
		}
		
		// Buiding a Max Heap using a random array.
		void buildMaxHeap() {
			for (int i = (size - 2) / 2; i != 0 && a[i] > a[parent(i)];) {
				maxHeapify(i);
				i = parent(i);
			}
		}
		
		void printHeap() {
			for (int i = 0; i < size; i++) {
				cout << a[i] << " ";
			}
		}
};


int main() {
	MaxHeap heap(10);
	for (int i = 1; i <= 10; i++) {
		heap.insert(i);
	}
	cout << heap.extractMax() << endl;
	
	cout << heap.extractMax() << endl;
	heap.printHeap();
	return 0;
}
