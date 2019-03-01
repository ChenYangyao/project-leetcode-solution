class Solution {
    func checkPossibility(_ nums: [Int]) -> Bool {
        if (nums.count < 3) {
            return true
        }
        
        var modified = nums[0] > nums[1]
        let length = nums.count
        for i in 1..<(length-2) {
            if (nums[i] > nums[i+1]) {
                //encounter decreasing twice
                if modified {
                    return false
                }
                //only two choices for changing one element: either change nums[i] or nums[i+1]
                //if nums[i-1] > nums[i+1], we must change nums[i+1]: e.g. 3,4,2 (i-1,i,i+1)
                //if nums[i] > nums[i+2], we must change nums[i]: e.g. 4,2,3 (i,i+1,i+2)
                //thus, if (nums[i-1] > nums[i+1] && nums[i] > nums[i+2]), change CANNOT be made: e.g. 3,4,2,3
                //head and tail are considered separately
                if (nums[i-1] > nums[i+1] && nums[i] > nums[i+2]) {
                    return false
                }
                modified = true
            }
        }
        
        return !(modified && nums[length-2] > nums[length-1])
    }
}
