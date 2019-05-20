class Solution {
    private var weights = [Int]()
    private var D = 0
    
    private func isEnough(_ capacity: Int) -> Bool {
        var tmpSum = 0; var counter = 0
        
        for weight in weights {
            if (tmpSum + weight <= capacity) {
                tmpSum += weight
            } else {
                tmpSum = weight
                counter += 1
            }
        }
        
        return counter < D
    }
    
    func shipWithinDays(_ weights: [Int], _ D: Int) -> Int {
        self.weights = weights
        self.D = D
        let length = weights.count
        
        var head = 0; var tail = 0
        var tmpSum = 0; let slice = min(length, max(length/D, length/D + 1))
        
        for idx in 0..<length {
            tmpSum += weights[idx]
            if (idx%slice == slice-1) {
                tail = max(tail, tmpSum)
                tmpSum = 0
            }
            head = max(head, weights[idx])
        }
        
        while (head < tail) {
            let mid = (head+tail)/2
            if isEnough(mid) {
                tail = mid
            } else {
                head = mid+1
            }
        }
        
        return head
    }
}
