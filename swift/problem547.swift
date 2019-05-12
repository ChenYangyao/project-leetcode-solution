//union-find
class UF {
    private var root: [Int]
    var setCount: Int
    
    init(_ N: Int) {
        self.root = [Int](0..<N)
        self.setCount = N
    }
    
    func find(_ x: Int) -> Int {
        if (root[x] != x) {
            root[x] = find(root[x])
        }
        return root[x]
    }
    
    func union(_ x: Int, _ y: Int) {
        let rootX = find(x)
        let rootY = find(y)
        if (rootX != rootY) {
            root[rootX] = rootY
            setCount -= 1
        }
    }
}

class Solution {
    func findCircleNum(_ M: [[Int]]) -> Int {
        let N = M.count
        let ufs = UF(N)
        
        for x in 0..<N {
            for y in (x+1)..<N {
                if (M[x][y] == 1) {
                    ufs.union(x, y)
                }
            }
        }
        
        return ufs.setCount
    }
}
