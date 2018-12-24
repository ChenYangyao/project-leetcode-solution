class Solution {
    func maxSubArray(_ nums: [Int]) -> Int {
        var sum = 0; var crest = Int.min
        
        for number in nums {
            sum += number
            crest = max(crest,sum)
            if (sum < 0) {
                sum = 0
            }
        }
        
        return crest
    }
}
