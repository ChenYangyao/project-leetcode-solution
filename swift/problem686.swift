import Foundation

class Solution {
    func repeatedStringMatch(_ A: String, _ B: String) -> Int {
        if !Set(B).isSubset(of: Set(A)) {
            return -1
        }
        
        var s = String(repeating: A, count: B.count/A.count)
        repeat {
            if s.contains(B) {
                return s.count/A.count
            } else {
                s += A
            }
        } while (s.count < B.count + 2*A.count)
        return -1
    }
}
