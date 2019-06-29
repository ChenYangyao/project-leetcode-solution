//ref: https://leetcode.com/problems/minimum-area-rectangle/solution/
//Approach 2
class Solution1 {
    func minAreaRect(_ points: [[Int]]) -> Int {
        let points = Set(points)
        var ans = Int.max
        
        for p1 in points {
            for p2 in points where (p1[0] != p2[0] && p1[1] != p2[1]){
                if (points.contains([p1[0],p2[1]]) && points.contains([p2[0],p1[1]])) {
                    ans = min(ans, abs((p1[0]-p2[0])*(p1[1]-p2[1])))
                }
            }
        }
        
        return ans == Int.max ? 0 : ans
    }
}

class Solution2 {
    func minAreaRect(_ points: [[Int]]) -> Int {
        let colMap = points.reduce(into: [Int:Set<Int>]()){$0[$1[0], default: Set<Int>()].insert($1[1])}
        var ans = Int.max
        
        let cols = colMap.keys.sorted()
        
        for xIdx1 in 0..<(cols.count - 1) {
            let xCoord1 = cols[xIdx1]
            let leftCol = Array(colMap[xCoord1]!)
            
            for yIdx1 in 0..<(leftCol.count - 1) {
                for yIdx2 in (yIdx1 + 1)..<leftCol.count {
                    for xIdx2 in (xIdx1 + 1)..<cols.count {
                        let xCoord2 = cols[xIdx2]
                        let rightCol = colMap[xCoord2]!
                        if (rightCol.contains(leftCol[yIdx1]) && rightCol.contains(leftCol[yIdx2])) {
                            ans = min(ans, abs(leftCol[yIdx2]-leftCol[yIdx1])*(xCoord2-xCoord1))
                        }
                    }
                }
            }
        }
        
        return ans == Int.max ? 0 : ans
    }
}
