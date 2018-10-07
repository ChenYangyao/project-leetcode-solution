class Solution {
    func isMonotonic(_ A: [Int]) -> Bool {
        let length = A.count - 1
        var start = 0
        
        if (length == 0) {
            return true
        }
        
        //find the first unequal index
        for index in 0..<length {
            if (A[index] == A[index+1]) {
                continue
            } else if (index == (length - 1)) {
                return true
            } else {
                start = index
                break
            }
        }
        
        if (A[start] > A[start+1]) {
            for index in start..<length {
                if (A[index] < A[index+1]) {
                    return false
                }
            }
        } else {
            for index in start..<length {
                if (A[index] > A[index+1]) {
                    return false
                }
            }
        }
        
        return true
    }
}

print([1],Solution().isMonotonic([1]))
print([1,1,2,3],Solution().isMonotonic([1,1,2,3]))
print([1,1,2,1],Solution().isMonotonic([1,1,2,1]))
print([3,2,1],Solution().isMonotonic([3,2,1]))
print([2,1,2],Solution().isMonotonic([2,1,2]))
