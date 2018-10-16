class Solution {
    func moveZeroes(_ nums: inout [Int]) {
        var last_non_zero = 0
        for index in 0..<nums.count {
            if (nums[index] == 0) {
                last_non_zero = index
                break
            }
        }
        
        for current in last_non_zero..<nums.count {
            if (nums[current] != 0) {
                if (last_non_zero != current) {
                    nums[last_non_zero] = nums[current]
                    nums[current] = 0
                }
                last_non_zero += 1
            }
        }
    }
}
