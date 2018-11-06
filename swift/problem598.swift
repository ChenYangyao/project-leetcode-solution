class Solution {
    func maxCount(_ m: Int, _ n: Int, _ ops: [[Int]]) -> Int {
        if (ops.count == 0) {
            return m*n
        }
        
        var min_row = 40_001
        var min_col = 40_001
        
        for operation in ops {
            min_row = min(operation[0],min_row)
            min_col = min(operation[1],min_col)
        }
        
        return min_row*min_col
    }
}
