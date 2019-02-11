//ref: leetcode.com/problems/magic-squares-in-grid/solution/133882/Magic-Squares-In-Grid/151459
class Solution {
    private let corner = [2: 8,
                          4: 6,
                          6: 4,
                          8: 2]
    private let side = [1: 9,
                        3: 7,
                        7: 3,
                        9: 1]
    private let sum = [2: 16,
                       4: 12,
                       6: 8,
                       8: 4]
    
    func numMagicSquaresInside(_ grid: [[Int]]) -> Int {
        let row = grid.count; let col = grid[0].count
        
        if (row < 3 || col < 3) {
            return 0
        }
        
        var ans = 0
        
        for x in 0..<(row - 2) {
            for y in 0..<(col - 2) {
                if (corner[grid[x][y]] == grid[x+2][y+2] && corner[grid[x+2][y]] == grid[x][y+2] && side[grid[x+1][y]] == grid[x+1][y+2] && side[grid[x][y+1]] == grid[x+2][y+1] && sum[grid[x][y]] == grid[x][y+1] + grid[x+1][y] && grid[x][y] != grid[x][y+2] && grid[x][y] != grid[x+2][y]) {
                    ans += 1
                }
            }
        }
        
        return ans
    }
}
