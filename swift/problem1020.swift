//DFS
class Solution {
    private var A = [[Int]]()
    private var maxRow = 0
    private var maxCol = 0
    
    func numEnclaves(_ A: [[Int]]) -> Int {
        self.A = A
        self.maxRow = A.count
        self.maxCol = A[0].count
        
        for row in [0,maxRow-1] {
            for col in 0..<maxCol {
                search(row,col)
            }
        }
        
        for row in 0..<maxRow {
            for col in [0,maxCol-1] {
                search(row,col)
            }
        }
        
        return self.A.flatMap{$0}.reduce(0,+)
    }
    
    private func edge(_ row: Int, _ col: Int) -> Bool {
        return (row >= 0 && row < maxRow && col >= 0 && col < maxCol)
    }
    
    private func search(_ row: Int, _ col: Int) {
        if (A[row][col] == 1) {
            A[row][col] = 0
            if edge(row+1,col) { search(row+1,col) }
            if edge(row-1,col) { search(row-1,col) }
            if edge(row,col+1) { search(row,col+1) }
            if edge(row,col-1) { search(row,col-1) }
        }
    }
}
