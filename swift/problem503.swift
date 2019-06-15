//ref: https://leetcode.com/problems/next-greater-element-ii/solution/
//Approach 3
class Solution {
    func nextGreaterElements(_ nums: [Int]) -> [Int] {
        if nums.isEmpty {
            return []
        }
        
        let length = nums.count
        var ans = [Int](repeating: -1, count: length)
        var stack = [Int]()
        
        for _ in 0...1 {
            for idx in (0..<length).reversed() {
                while (!stack.isEmpty && stack.last! <= nums[idx]) {
                    stack.removeLast(1)
                }
                if !stack.isEmpty {
                    ans[idx] = stack.last!
                }
                stack.append(nums[idx])
            }
        }
        
        return ans
    }
}
