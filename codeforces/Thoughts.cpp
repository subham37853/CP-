
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



"A -> B -> E -> C -> D" are all the nodes visited? 


Ans should be either the sequence or true.












