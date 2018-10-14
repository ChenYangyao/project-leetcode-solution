class Solution {
    func moveZeroes(_ nums: inout [Int]) {
        var last_non_zero = 0
        for current in 0..<nums.count {
            if (nums[current] != 0) {
                nums.swapAt(last_non_zero, current)
                last_non_zero += 1
            }
        }
    }
}
