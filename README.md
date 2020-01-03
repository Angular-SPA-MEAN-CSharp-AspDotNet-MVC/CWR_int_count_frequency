# This repo is developed in Visual Studio 2013 Ultimate version. The quesion and brielf explanation are below: 

Question:

Coding homework: Given a sorted array of N elements with duplicates, for example:

a,b,b,b,b,b,d,h,h,h,p

count the number of occurrences of each unique element.

1a) Solve this with an O(N) algorithm
1b) Solve this with a better-than-O(N) algorithm and analyze its time complexity.

While it may be useful to run your code with the example array above, please also test it with a larger (ex., 100-1000 elements) randomly generated, sorted array.


Explanation of the Code:
Two methods are implemented to approach this question, in the file "main.cpp".
1. "void countProcess(char ary[], int size)" will count the occurences through iteration the array. The time complexity is O(N)
2. "void countFastProcess(char ary[], int size)" will count the occrences through the "binary search". Since the number of item tpyes R is much less than the total item count N, the time complexity is O(logN).

Please contact me if there is a correction, a comment, or a more efficient solution. My email is knhg2013@gmail.com

Many Thanks!!!!

