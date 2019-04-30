//ref: https://leetcode.com/problems/product-of-array-except-self/discuss/65622/Simple-Java-solution-in-O(n)-without-extra-space
class Solution {
    func productExceptSelf(_ nums: [Int]) -> [Int] {
        var ans = [Int](repeating: 1, count: nums.count)
        
        for idx in 1..<nums.count {
            ans[idx] = ans[idx-1]*nums[idx-1]
        }
        
        var right = 1
        for idx in (0..<nums.count).reversed() {
            ans[idx] *= right
            right *= nums[idx]
        }
        
        return ans
    }
}
