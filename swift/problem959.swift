//union-find-by-rank
/**
 class UFR {
 private var root: [Int]
 private var rank: [UInt16]
 
 init(_ n: Int) {
 self.root = [Int](0..<n)
 self.rank = [Int](repeating: 0, count: n)
 }
 
 func find(_ x: Int) -> Int {
 if (root[x] != x) {
 root[x] = find(root[x])
 }
 return root[x]
 }
 
 func union(_ x: Int, _ y: Int) {
 let xroot = root[find(x)]
 let yroot = root[find(y)]
 
 if (xroot == yroot) {
 return
 }
 
 if (rank[xroot] < rank[yroot]) {
 root[xroot] = yroot
 } else if (rank[xroot] > rank[yroot]) {
 root[yroot] = xroot
 } else {
 root[yroot] = xroot
 rank[xroot] += 1
 }
 }
 }
**/

//union-find
class UFR {
    private var root: [Int]
    
    init(_ n: Int) {
        self.root = [Int](0..<n)
    }
    
    func find(_ x: Int) -> Int {
        if (root[x] != x) {
            root[x] = find(root[x])
        }
        return root[x]
    }
    
    func union(_ x: Int, _ y: Int) {
        root[find(x)] = find(y)
    }
}

//ref: https://leetcode.com/problems/regions-cut-by-slashes/solution/
class Solution {
    func regionsBySlashes(_ grid: [String]) -> Int {
        let n = grid.count
        let unionFind = UFR(4*n*n)
        
        for r in 0..<n {
            let chars = grid[r].map{$0}
            for c in 0..<n {
                let parent = 4*(r*n+c)
                let val = chars[c]
                if (val != "\\") {
                    unionFind.union(parent,parent+1)
                    unionFind.union(parent+2,parent+3)
                }
                if (val != "/") {
                    unionFind.union(parent,parent+2)
                    unionFind.union(parent+1,parent+3)
                }
                
                if (r+1<n) {
                    unionFind.union(parent+3,parent+4*n)
                }
                if (r-1>=0) {
                    unionFind.union(parent,parent-4*n+3)
                }
                if (c+1<n) {
                    unionFind.union(parent+2,parent+5)
                }
                if (c-1>=0) {
                    unionFind.union(parent+1,parent-2)
                }
            }
        }
        
        var ans = 0
        for x in 0..<(4*n*n) {
            if (unionFind.find(x) == x) {
                ans += 1
            }
        }
        
        return ans
    }
}
