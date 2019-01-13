class Solution {
    func pivotIndex(_ nums: [Int]) -> Int {
        let sum = nums.reduce(0,+); var left = 0
        
        for i in 0..<nums.count {
            let tmp = left + nums[i]
            if (left == sum - tmp) {
                return i
            }
            left = tmp
        }
        
        return -1
    }
}
