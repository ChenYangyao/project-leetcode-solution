class Solution {
    func findLengthOfLCIS(_ nums: [Int]) -> Int {
        if (nums.count < 2) {
            return nums.count
        }
        
        var deb = 0; var fin = 0
        var prev = nums[0] - 1; var maxl = 0
        
        for number in nums {
            if (number <= prev) {
                maxl = max(maxl,fin-deb)
                deb = fin
            }
            prev = number
            fin += 1
        }
        
        return max(maxl,fin-deb)
    }
}
