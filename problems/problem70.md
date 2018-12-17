## Problem 70: Climbing Stairs

problem: [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/)

### Solution

- [Python](../python/problem70.py)

- [C++](../cpp/problem70.cpp)

- [Swift](../swift/problem70.swift)

### Discussion

We try to solve this problem mathematically. First, we consider the possible number of permutations for `k` twos and `n-2k` ones. It is easy to show that the answer is (Imaging we need to put `k` identical balls into `n-2k+1` different boxes)

![equation](https://latex.codecogs.com/gif.latex?%7B%7Bn-k%7D%5Cchoose%7Bn-2k%7D%7D).

Then, the total possible ways to climb the stair can be obtained by summing all possible `k`s, i.e.,

![equation](https://latex.codecogs.com/gif.latex?%5Csum_%7Bk%3D0%7D%5E%7B%5Bn/2%5D%7D%7B%7B%7Bn-k%7D%5Cchoose%7Bn-2k%7D%7D%7D%3D%5Csum_%7Bk%3D0%7D%5E%7B%5Bn/2%5D%7D%7B%7B%7Bn-k%7D%5Cchoose%7Bk%7D%7D%7D%3DF%28n&plus;1%29),

where `F` is the Fibonacci sequence.

The final result is exactly the same as being revealed by [Approach 3: Dynamic Programming](https://leetcode.com/problems/climbing-stairs/solution/). Thus, this problem actually provides a proof for the fact that the [fibonacci numbers](https://en.wikipedia.org/wiki/Fibonacci_number#Use_in_mathematics) are the sums of the "shallow" diagonals of Pascal's triangle.
