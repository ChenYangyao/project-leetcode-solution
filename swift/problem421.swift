//ref: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/discuss/276621/C%2B%2B-bit-manipulation()-solution-with-o(n)-time-and-o(n)-space
class Solution {
    func findMaximumXOR(_ nums: [Int]) -> Int {
        var mask = 0
        var test = 0
        var ans = 0
        
        for i in (0..<31).reversed() {
            mask |= (1 << i)
            test = ans | (1 << i)
            var bitSet = Set<Int>()
            for number in nums {
                let cur = number & mask
                bitSet.insert(cur)
                if bitSet.contains(cur ^ test) {
                    ans = test
                    break
                }
            }
        }
        
        return ans
    }
}
