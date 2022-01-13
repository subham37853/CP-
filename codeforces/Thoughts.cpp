
given an array
constraints: 
-1e5 <= a[i] <= 1e5
0 <= n <= 200

choices:
i can choose at most x times a subarray of size 1
i can choose at most y times a subarray of size 2
i can choose at most z times a subarray of size 3

Note: the subarray should be non overlapping
profit is the sum of the selected subarray
goal: is to maximize the profit.

[1,2,3,-4,5]
x = 1
y = 1
z = 1

{3, 4, 5} chosen 1 time -> profit = 12
{1, 2} chosen 1 time -> profit = 3
net profit = 15

my thought process during the Online Assesment was to use recurrsion.





Node : A B C D E 
com 		need to know
B 		->         A 
C       -> 		   B
D 		-> 		   C
E  		-> 		   A
A 		-> 		   0 prerequisite

The goal is to find whether you are able to complete/visited/make all the nodes.



"A -> B -> E -> C -> D" are all the nodes visited? "
Ans should be either the sequence or true.


void print(string name, int n) {
	if (n == 0) return;
	cout << name << endl;
	print(name, n);
}

void print(string name) {
	for (int i = 0; i < 1; i) {
		cout << name << endl;
	}
}
//Why this did not overflow the stack?

void solve() {
	...
}
int main() {
	int n;
	cin >> n;
	solve();
	getAllmax();
	return 0;
}
// this is a function for fibbonacci series 
// 0 1 1 2 3 5 8 13 ...
// currelement is what? the sum of previous two 
 /*
 2 =  1 + 1 
 3 = 2 + 1
 5 = 3 + 2
 .
 .
 .
 n = prev[(n - 1)] + prev[(n - 2)]
 */
int fibo(int n) {
	if (n == 0 || n == 1) return n;
	int prev = fibo(n - 1);
	int prevPrev = fibo(n - 2);
	return prev + prePrev;
}







problem statement: 
Given an array called values and weight of the corresponding values array find the maximum value you can get under the given weight W.
// other words: 
Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. 

sample input:

value: {60, 100, 120}
weight: {10, 20, 30}
W = 50;
constraints:
N <= 1000
W <= 1000
a[i] <= 1000














