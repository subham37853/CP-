int curr = INT_MAX;
for (int i =0; i < n; i++) {
	curr = min(curr, a[i]);
}


minimum find krne k liye ye code hai... which will give O(n) time complexity.


L,R -> found out in O(n);

what if there are a lot of L and R

L, R jo diya hua hai wo hai queries.

Lets say there are "q" number of queries.

vector<int> a(n);

for (int i = 0; i < Q; i++) {
	int L, R;
	cin >> L >> R;
	int curr = INT_MAX;
	for (int i =0; i < N; i++) {
		curr = min(curr, a[i]);
	}
	cout << curr << endl;
}

I have to take the input Q times 



Total complexity of the above code is O(Q*N); This complexity is very bad when the constraints are "N and Q are <= 10^6"

10^6 * 10^6 = 10^12....

pehle se hi minimum values ko store kr k rakhe to N wala jo code hai wo optimise ho skta hai thoda bahut. 

Segment Tree.


What is a segment tree



storing values for a small interval
then merging those values for the bigger intervals


1 - 3.     3 - 6

2 4 3      1 4 2 7
2          1

	  1 Ultimate Ans. 

2 1 -> 1 2 
4 3 -> 3 4 

1 2 3 4




2 4 1 3 5 6


L R

What is the smallest range possible -> 1 

min of 1 -> 1 
can we say smallest range can of length 1 element can be minimum of itself and maximum itself. 
3 -> min 3 
3 -> max 3 



2 1 4 3 5 6


0 1 2


2 - 5 

 4.     3
(2-2) (3-5)

min(2-5) = 3


1 - 4

(1-1) (2-2) (3-4) ye tino ka minimum is the answer; 




10 -> 1010 -> 2^3 + 0 + 2^1 + 0 = 10


0 - 1 left right - 2 2


low - mid =  left

mid + 1, high = right

2 1 4 -> (2 1) (4) -> (2) (1) (4) -> 1 is the Answer.



								 0-5

						0-2 	 		3-5

					seg[index] = min(seg[2*index + 1], seg[2*index + 2]);
					0-1      2-2    3-4		 5-5

		2*index + 1.  2*index + 2
				0-0.   1-1		3-3.   4-4.   


				height == ? 

what info we have is : 
the maximum number of nodes can be made out of an array is 4 * n + 1 where n is the size of the array 




always keep in mind the the position of a child is dependent upon its parent

so if the parent's position is i -> then 
left child is 2 * i + 1 
right child is 2 * i + 2

2 1 4 3 5 6




2 1 4 0 5 6