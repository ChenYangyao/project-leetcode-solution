class Solution {
    func removeDuplicates(_ nums: inout [Int]) -> Int {
        var length = nums.count
        
        if (length == 0) {
            return 0
        }
        
        var i = 0
        
        for j in 1..<length {
            if (nums[j] != nums[i]) {
                i += 1
                nums[i] = nums[j]
            }
        }
        
        return (i+1)
    }
}
