class Solution {
    func maxIncreaseKeepingSkyline(_ grid: [[Int]]) -> Int {
        let length = grid.count
        var rowMax = Array(repeating: -1, count: length)
        var colMax = Array(repeating: -1, count: length)
        var prevSum = 0
        
        for row in 0..<length {
            for col in 0..<length {
                let tmp = grid[row][col]
                prevSum -= tmp
                rowMax[row] = max(rowMax[row],tmp)
                colMax[col] = max(colMax[col],tmp)
            }
        }
        
        for row in 0..<length {
            for col in 0..<length {
                prevSum += min(rowMax[row],colMax[col])
            }
        }
        
        return prevSum
    }
}
