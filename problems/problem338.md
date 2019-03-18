## Problem 338: Counting Bits

problem: [Counting Bits](https://leetcode.com/problems/counting-bits/)

### Solution

- [Python](../python/problem338.py)

- [C++](../cpp/problem338.cpp)

- [Swift](../swift/problem338.swift)

- [Java](../java/problem338.java)

### Discussion

Since the question requires an one-pass O(n) solution, a recursive relation is preferred to use.

For any non-negative natural number, it is either even or odd. For an even number, the last digit of its binary form must be zero, and the right bit shift will NOT change the bit count, i.e.
```text
	bitCount[i] = bitCount[i >> 1] // i is even.
```

For an odd number, since the last digit is 1, right bit shift will reduce one of the bit count, i.e.
```text
	bitCount[i] = bitCount[i >> 1] + 1 // i is odd
```

In summary, we can write down the following recursive relation:
```text
	bitCount[i] = bitCount[i >> 1] + i & 1
```
or equivalently
```text
	bitCount[i] = bitCount[i / 2] + i % 2 //for python, use i // 2 instead.
```
