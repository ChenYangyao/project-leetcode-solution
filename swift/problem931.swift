class Solution {
    func minFallingPathSum(_ A: [[Int]]) -> Int {
        var A = A
        let row = A.count; let col = A[0].count
        
        if (row == 1) {
            return A[0][0]
        } else if (row == 2) {
            return A[0].min()! + A[1].min()!
        }
        
        for r in 1..<row {
            for c in 0..<col {
                switch c {
                case 0:
                    A[r][c] += min(A[r-1][c], A[r-1][c+1])
                case col-1:
                    A[r][c] += min(A[r-1][c-1], A[r-1][c])
                default:
                    A[r][c] += min(A[r-1][c-1], A[r-1][c], A[r-1][c+1])
                }
            }
        }
        
        return A[row-1].min()!
    }
}
