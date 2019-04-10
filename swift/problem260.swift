//refer to the approach 7 of problem645
//https://leetcode.com/problems/set-mismatch/solution/
class Solution {
    func singleNumber(_ nums: [Int]) -> [Int] {
        let rightmostbit = {xor in xor & ~(xor-1)}(nums.reduce(0,^))
        
        var set = 0; var unset = 0
        
        for number in nums {
            if (number & rightmostbit == 0) {
                unset ^= number
            } else {
                set ^= number
            }
        }
        
        return [set,unset]
    }
}
