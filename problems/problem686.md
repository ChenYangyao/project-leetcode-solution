## Problem 686: Repeated String Match

problem: [Repeated String Match](https://leetcode.com/problems/repeated-string-match/)

### Solution

- [Python](../python/problem686.py)

- [C++](../cpp/problem686.cpp)

- [Swift](../swift/problem686.swift)

- [Java](../java/problem686.java)

### Discussion

In the official solution `Approach 2: Rabin-Karp (Rolling Hash)` method, they provide a solution with `O(1)` space cost and linear time complexity. The key point is to hash every substring (with length B.size) of A + A + ... + A by the hash function
```txt
hash(S[0...n[) = S[0] + p*S[1] + ... + p^(n-1)*S[n - 1],
```
where p is a primer. The subsequent hash can be obtained by
```txt
hash(S[1...n+1[) = ( hash(S[0...n[) - S[0] )/p + p^(n-1)*S[n].
```
However, the value p^(n-1) may easily become very large, so that the computation of hash key, the comparison between keys, and the storage for keys become linearly complicated with length of string.

To overcome this problem, we provide a small modification. We directly use the following hash function
```txt
hash(S[0...n[) = S[0] + S[1] + ... + S[n-1]
```
The subsequent hash key is also easily to be computated. By removing the primer p, we decrease the hash key to a integer small enough so the space of this algorithm REALLY become O(1). Time time comlexity, on average, is still acceptable because the collision rate of hash key, especially for long string, is small.

But this unaoidably introduce bad cases. In the worst situation, e.g., A = "acacac...(very long)...acacac", B = "bbbb...(even size, also very long but much shorter than A)", the hash key of them collides every time, so the time complexity become Theta(A.size*B.size). 


