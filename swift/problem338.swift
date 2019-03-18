//ref: https://leetcode.com/problems/counting-bits/
class Solution {
    func countBits(_ num: Int) -> [Int] {
        var bitCount = [Int](repeating: 0, count: num + 1)
        
        for i in 0...num {
            bitCount[i] = bitCount[i>>1] + i&1
        }
        
        return bitCount
    }
}
