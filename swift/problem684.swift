//union-find-by-rank
class UFR {
    private var root: [Int]
    private var rank: [UInt16]
    
    init(_ n: Int) {
        self.root = [Int](0..<n)
        self.rank = [UInt16](repeating: 0, count: n)
    }
    
    func find(_ x: Int) -> Int {
        if (root[x] != x) {
            root[x] = find(root[x])
        }
        return root[x]
    }
    
    func union(_ x: Int, _ y: Int) -> Bool {
        let xroot = root[find(x)]
        let yroot = root[find(y)]
        
        if (xroot == yroot) {
            return true
        }
        
        if (rank[xroot] < rank[yroot]) {
            root[xroot] = yroot
        } else if (rank[xroot] > rank[yroot]) {
            root[yroot] = xroot
        } else {
            root[yroot] = xroot
            rank[xroot] += 1
        }
        
        return false
    }
}

class Solution {
    func findRedundantConnection(_ edges: [[Int]]) -> [Int] {
        let ufs = UFR(edges.count)
        
        for edge in edges {
            if ufs.union(edge[0] - 1, edge[1] - 1) {
                return edge
            }
        }
        
        return []
    }
}
