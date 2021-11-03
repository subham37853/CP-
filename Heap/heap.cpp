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
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif 


this is the implementation of binary heap
this is the implementation of the binary min heap


// Min Heap class
void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}
class MinHeap {
	public: 
	int *arr;
	int size;
	int capacity;
	
	// contructor for initialisatoin 
	MinHeap(int c) {
		arr = new int[c];
		size = 0;
		capacity = c;
	}
	
	// find the left element of root "i"
	int left(int i) {
		return (2*i + 1);
	}
	
	// find the right element of root "i"
	int right(int i) {
		return (2*i + 2);
	}
	
	// find the parent of root "i"
	int parent(int i) {
		return (i - 1)/2;
	}
	
	// method to implement insert operation in binary MinHeap
	bool insert(int val) {
		if (size == capacity) {
			return false;
		}
		size += 1;
		// putting element at the last index of the array
		arr[size - 1] = val;
		for (int i = size - 1; i != 0 && arr[parent(i)] > arr[i];) {
			swap(arr[i], arr[parent(i)]);
			i = parent(i);
		}
		return true;
	}
	
	// Heapify Operation in Binary Min Heap
	// worst case time complexity of heapify is O(H) where H is the height of the binary tree
	// Space complextity is O(H).
	void heapify(int i) {
		int l = left(i);
		int r = right(i);
		int smallest = i;
		if (l < size && arr[l] < arr[smallest]) smallest = l;
		if (r < size && arr[r] < arr[smallest]) smallest = r;
		if (smallest != i) {
			swap(&arr[i], &arr[smallest]);
			heapify(smallest);
		}
	}
	
	// Method to find the minimum value of Min Heap. 
	// Time Complexity is O(1)
	int getMin() {
		return arr[0];
	}
	
	// Method to find the minimum element from the Min Heap and removes the minimumm element as well
	
	int extractMin() {
		if (size == 0) return INT_MAX;
		if (size == 1) {
			size -= 1;
			return arr[0];
		}
		swap(&arr[0], &arr[size-1]);
		size -= 1;
		heapify(0);
		return arr[size];
	}
	
	// Method to print the Heap
	void printHeap() {
		for (int i = 0; i < size; i++) {
			cout << arr[i] << " ";
		}
	}
	
	// Method for updating/decreasing a value in binary Min Heap
	
	void update(int i, int val) {
		arr[i] = val;
		while (i != 0 && arr[parent(i)] > arr[i]) {
			swap(arr[parent(i)], arr[i]);
			i = parent(i);
		}
	}
	
	// Method to delete a particular value in Min Heap
	
	void deleteNode(int i) {
		update(i, INT_MIN);
		extractMin();
	}
	
	// Method for building a Min Heap from a random array
	void buildMinHeap() {
		for (int i = (size - 2) / 2; i >= 0; i--) {
			heapify(i);
		}
	}
	
	// Program to covert a min heap to max heap
	
	void maxHeapify(vector<int> &a, int i) {
		int largest = i;
		int l = 2 * i + 1;
		int r = 2 * i + 2;
		if (l < a.size() && a[l] > a[largest]) largest = l;
		if (r < a.size() && a[r] > a[largest]) largest = r;
		if (largest != i) {
			swap(a[i], a[largest]);
			maxHeapify(a, largest);
		}
	}
	
	void convert(vector<int> &a) {
		for (int i = a.size() - 1; i >= 0; i--) {
			maxHeapify(a, i);
		}
	}
};

int main() {
	//~ MinHeap heap(10);
	//~ for (int i = 10; i >= 1; i--) {
		//~ heap.insert(i);
		//~ heap.heapify(10 - i);
	//~ }
	//~ heap.printHeap();
	//~ cout << heap.extractMin() << endl;
	
	//~ cout << heap.extractMin() << endl;
	vector<int> a;
	MinHeap heap(10);
	heap.convert(a);
	return 0;
}
