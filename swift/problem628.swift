class Solution {
    func maximumProduct(_ nums: [Int]) -> Int {
        let length = nums.count
        
        // for small arrays, use simple and direct method
        if (length == 3) {
            return nums.reduce(1,*)
        } else if (length == 4) {
            let nums = nums.sorted()
            return max(nums[0]*nums[1]*nums[3],nums[1]*nums[2]*nums[3])
        }
        
        //min_2 min_1 ... max_1 max_2 max_3 for nums.sorted()
        var min_2 = Int.max; var min_1 = Int.max
        var max_1 = Int.min; var max_2 = Int.min; var max_3 = Int.min
        
        for num in nums {
            if (num < min_1) {
                if (num < min_2) {
                    min_1 = min_2
                    min_2 = num
                } else {
                    min_1 = num
                }
            }
            //shouldn't be 'else if'
            if (num > max_1) {
                if (num > max_2) {
                    if (num > max_3) {
                        max_1 = max_2
                        max_2 = max_3
                        max_3 = num
                    } else {
                        max_1 = max_2
                        max_2 = num
                    }
                } else {
                    max_1 = num
                }
            }
        }
        
        return max(min_2*min_1*max_3,max_1*max_2*max_3)
    }
}
