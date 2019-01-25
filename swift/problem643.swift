class Solution {
    func findMaxAverage(_ nums: [Int], _ k: Int) -> Double {
        if (nums.count <= k) {
            return Double(nums.reduce(0,+))/Double(k)
        }
        
        var prev = nums[0..<k].reduce(0,+); var prevMax = prev
        for index in k..<nums.count {
            let tmp = nums[index] - nums[index-k] + prev
            prev = tmp
            prevMax = max(prevMax,tmp)
        }
        
        return Double(prevMax)/Double(k)
    }
}
