//should be classified as simple problem
class RLEIterator {
    private var A: [Int]
    private var exhausted, currentIdx, length: Int
    
    init(_ A: [Int]) {
        self.A = A
        self.exhausted = 0
        self.currentIdx = 0
        self.length = A.count
    }
    
    func next(_ n: Int) -> Int {
        var n = n
        
        while (currentIdx < length) {
            if (n + exhausted <= A[currentIdx]) {
                exhausted += n
                return A[currentIdx+1]
            } else {
                n -= (A[currentIdx] - exhausted)
                exhausted = 0
                currentIdx += 2
            }
        }
        
        return -1
    }
}
