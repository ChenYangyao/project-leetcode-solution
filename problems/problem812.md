## Problem 812: Largest Triangle Area

problem: [Largest Triangle Area](https://leetcode.com/problems/largest-triangle-area/)

### Solution

- [Python](../python/problem812.py)

- [C++](../cpp/problem812.cpp)

- [Swift](../swift/problem812.swift)

### Discussion

**Basic solution**

It is natural to solve this problem by traverse throughout all the points able to form triangles. The time complexity is `O(n^3)`.

```swift
let length = points.count

for p1 in 0..<(length-2) {
    for p2 in (p1+1)..<(length-1) {
        for p3 in (p2+1)..<length {
	    maxArea = max(maxArea,Area(points[p1],points[p2],points[p3]))
        }
    }
}
```

Also, the area of triangle could be calculated using cross product. Since all the points are on integer grids, so the cross product of them is still an integer which allows us to use integer type to store Area.

**Convex Hull Algorithms**

It is obvious that the points form largest triangle must be on the convex hull of the sets of points. Thus we first find out all the convex hull points and then only traverse through them.

Many convex hull algorithms are available in [wikibooks](https://en.wikibooks.org/wiki/Algorithm_Implementation/Geometry/Convex_hull). Here we implement monotone chain algorithm with time complexity `O(n)` provided with lexicographically sorted points set.
