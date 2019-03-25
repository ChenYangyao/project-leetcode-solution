//union-find-by-rank
/**
class UFR {
    private class element {
        var parent: Int
        var rank: Int
        
        init(_ parent: Int, _ rank: Int) {
            self.parent = parent
            self.rank = rank
        }
        
        static func ==(left: element, right: element) -> Bool {
            return left.parent == right.parent && left.rank == right.rank
        }
    }
    
    private var root: [element]
    
    init(_ n: Int) {
        self.root = zip([Int](0..<n), [Int](repeating: 0, count: n)).map{element($0,$1)}
    }
    
    func find(_ x: Int) -> Int {
        if (root[x].parent != x) {
            root[x].parent = find(root[x].parent)
        }
        return root[x].parent
    }
    
    func union(_ x: Int, _ y: Int) {
        let xroot = root[find(x)]
        let yroot = root[find(y)]
        
        if (xroot == yroot) {
            return
        }
        
        if (xroot.rank < yroot.rank) {
            xroot.parent = yroot.parent
        } else if (xroot.rank > yroot.rank) {
            yroot.parent = xroot.parent
        } else {
            yroot.parent = xroot.parent
            xroot.rank += 1
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
