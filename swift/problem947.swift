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
        let idxRow = find(x)
        let idxCol = find(y)
        if (idxRow != idxCol) {
            root[idxRow] = idxCol
            setCount -= 1
        }
    }
}

class Solution {
    func removeStones(_ stones: [[Int]]) -> Int {
        let ufs = UF()
        
        for stone in stones {
            ufs.union(stone[0], stone[1] + 10000)
        }
        
        return stones.count - ufs.setCount
    }
}
