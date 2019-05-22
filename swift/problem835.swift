public struct vec {
    public var x: Int
    public var y: Int
    
    public init(_ x: Int, _ y: Int) {
        self.x = x
        self.y = y
    }
}

extension vec: Hashable {
    public var hashValue: Int {
        var hasher = Hasher()
        hash(into: &hasher)
        return hasher.finalize()
    }
    
    public func hash(into hasher: inout Hasher) {
        hasher.combine(self.x)
        hasher.combine(self.y)
    }
}

extension vec {
    public static func - (lhs: vec, rhs: vec) -> vec {
        return vec(lhs.x - rhs.x, lhs.y - rhs.y)
    }
}

//ref: https://leetcode.com/problems/image-overlap/discuss/138976/A-generic-and-easy-to-understand-method
class Solution {
    func largestOverlap(_ A: [[Int]], _ B: [[Int]]) -> Int {
        var Apts = [vec](); var Bpts = [vec]()
        var counter = [vec:Int]()
        
        for row in 0..<A.count {
            for col in 0..<A.count {
                if (A[row][col] == 1) {
                    Apts.append(vec(row, col))
                }
                if (B[row][col] == 1) {
                    Bpts.append(vec(row, col))
                }
            }
        }
        
        for Apt in Apts {
            for Bpt in Bpts {
                counter[Apt-Bpt, default: 0] += 1
            }
        }
        
        return counter.values.max() ?? 0
    }
}
