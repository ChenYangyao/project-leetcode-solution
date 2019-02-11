class Solution {
    func validMountainArray(_ A: [Int]) -> Bool {
        let length = A.count
        
        if (length < 3 || A[1] < A[0]) {
            return false
        }
        
        var flag = true; var prev = A[1]
        
        for i in 2..<length {
            if flag {
                if (A[i] < prev) {
                    flag = false
                } else if (A[i] == prev){
                    return false
                }
            } else {
                if (A[i] >= prev) {
                    return false
                }
            }
            prev = A[i]
        }
        
        return !flag
    }
}
