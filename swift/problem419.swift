class Solution {
    func countBattleships(_ board: [[Character]]) -> Int {
        if (board.isEmpty || board[0].isEmpty) {
            return 0
        }
        
        var ans = 0; let x = Character("X")
        
        for row in 0..<board.count {
            for col in 0..<board[0].count {
                if (board[row][col] == x && (row == 0 || board[row-1][col] != x) && (col == 0 || board[row][col-1] != x)) {
                    ans += 1
                }
            }
        }
        
        return ans
    }
}
