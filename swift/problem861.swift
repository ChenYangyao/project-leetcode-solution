//ref: https://leetcode.com/problems/score-after-flipping-matrix/solution/
//Approach2
class Solution {
    func matrixScore(_ A: [[Int]]) -> Int {
        let rowCount = A.count; let colCount = A[0].count
        var ans = 0
        
        for col in 0..<colCount {
            var colSum = 0
            for row in 0..<rowCount {
                //the key is we don't really need to judge whether A[][0] should be toggled
                colSum += (A[row][col]^A[row][0])
            }
            //by noting that the max sum must be max(colSum, rowCount - colSum)
            ans <<= 1; ans += max(colSum, rowCount - colSum)
        }
        
        return ans
    }
}
