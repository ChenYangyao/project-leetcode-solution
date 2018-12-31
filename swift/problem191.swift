//ref: https://leetcode.com/problems/number-of-1-bits/solution/
class Solution {
    func hammingWeight(_ n: UInt32) -> Int {
        var bitCount = 0; var n = n
        while (n != 0) {
            bitCount += 1
            n &= (n-1)
        }
        return bitCount
    }
}
