//union-find
class UF {
    private var root: [Int:Int]
    var setCount: Int
    
    init() {
        self.root = [Int:Int]()
        self.setCount = 0
    }
    
    func find(_ x: Int) -> Int {
        if (root[x] != x) {
            if (root[x] != nil) {
                root[x] = find(root[x]!)
            } else {
                root[x] = x
                setCount += 1
            }
        }
        return root[x]!
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
        let ufs = UF()
        
        for x in 0..<M.count {
            for y in x..<M[0].count {
                if (M[x][y] == 1) {
                    ufs.union(x, y)
                }
            }
        }
        
        return ufs.setCount
    }
}
