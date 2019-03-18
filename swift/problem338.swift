//ref: https://leetcode.com/problems/counting-bits/
class Solution {
    func countBits(_ num: Int) -> [Int] {
        var bitCount = [Int](repeating: 0, count: num + 1)
        
        if (num == 0) {
            return bitCount
        }
        
        for i in 1...num {
            bitCount[i] = bitCount[i>>1]+i&1
        }
        
        return bitCount
    }
}
