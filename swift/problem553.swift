class Solution {
    func optimalDivision(_ nums: [Int]) -> String {
        var ans = String(nums[0])
        switch nums.count {
            case 1:
            return ans
            case 2:
            return ans + "/" + String(nums[1])
            default:
            ans += ("/(" + String(nums[1]))
        }
        
        for idx in 2..<nums.count {
            ans += ("/" + String(nums[idx]))
        }
        
        ans += ")"
        
        return ans
    }
}
