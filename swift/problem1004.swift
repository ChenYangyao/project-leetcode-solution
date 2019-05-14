//ref: https://leetcode.com/problems/max-consecutive-ones-iii/discuss/247543/O(n)-Java-Solution-using-sliding-window
class Solution {
    func longestOnes(_ A: [Int], _ K: Int) -> Int {
        var zeroCount = 0; var head = 0; var ans = 0
        
        for tail in 0..<A.count {
            if (A[tail] == 0) {
                zeroCount += 1
            }
            
            while (zeroCount > K) {
                if (A[head] == 0) {
                    zeroCount -= 1
                }
                head += 1
            }
            
            ans = max(ans, tail - head + 1)
        }
        
        return ans
    }
}
