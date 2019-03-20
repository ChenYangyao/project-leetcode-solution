class Solution {
    private let op = [(true,1),(false,1),(true,-1),(false,-1)] //first: true for row, false for col; second: 1 forward, -1 backward
    private var ans = [[Int]]()
    private var current = [Int]()
    var visited = 1
    
    func spiralMatrixIII(_ R: Int, _ C: Int, _ r0: Int, _ c0: Int) -> [[Int]] {
        var step = 1; var turningCount = 0
        self.visited = 1
        self.current = [r0,c0]
        self.ans = [current]
        let total = R*C
        
        while (visited != total) {
            let turningSignal = op[turningCount%4]
            move(turningSignal.0, turningSignal.1, step, R, C)
            turningCount += 1
            if (turningCount&1 == 0) {
                step += 1
            }
        }
        
        return ans
    }
    
    private func move(_ direction: Bool, _ forward: Int, _ step: Int, _ R: Int, _ C: Int) {
        for _ in 0..<step {
            if direction {
                current[1] += forward
            } else {
                current[0] += forward
            }
            let row = current[0]; let col = current[1]
            if (row < R && row >= 0 && col < C && col >= 0) {
                ans.append(current)
                visited += 1
            }
        }
    }
}
