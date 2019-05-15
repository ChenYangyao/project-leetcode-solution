class Solution {
    private var board = [[Character]]()
    private var maxRow = 0
    private var maxCol = 0
    
    func updateBoard(_ board: [[Character]], _ click: [Int]) -> [[Character]] {
        self.board = board
        self.maxRow = board.count
        self.maxCol = board[0].count
        
        if (self.board[click[0]][click[1]] == "M") {
            self.board[click[0]][click[1]] = "X"
            return self.board
        }
        
        minesweeper(click[0], click[1])
        
        return self.board
    }
    
    private func edge(_ row: Int, _ col: Int) -> Bool {
        return (row >= 0 && row < maxRow && col >= 0 && col < maxCol)
    }
    
    private func counter(_ row: Int, _ col: Int, _ mineCount: inout Int) {
        if (edge(row, col) && board[row][col] == "M") {
            mineCount += 1
        }
    }
    
    private func next(_ row: Int, _ col: Int) {
        if (edge(row, col) && board[row][col] == "E") {
            minesweeper(row, col)
        }
    }
    
    private func minesweeper(_ row: Int, _ col: Int) {
        var mineCount = 0
        counter(row+1, col-1, &mineCount)
        counter(row+1, col, &mineCount)
        counter(row+1, col+1, &mineCount)
        counter(row, col+1, &mineCount)
        counter(row, col-1, &mineCount)
        counter(row-1, col-1, &mineCount)
        counter(row-1, col, &mineCount)
        counter(row-1, col+1, &mineCount)
        
        if (mineCount != 0) {
            board[row][col] = Character(String(mineCount))
            return
        }
        
        board[row][col] = "B"
        
        next(row+1, col-1)
        next(row+1, col)
        next(row+1, col+1)
        next(row, col+1)
        next(row, col-1)
        next(row-1, col-1)
        next(row-1, col)
        next(row-1, col+1)
    }
}
