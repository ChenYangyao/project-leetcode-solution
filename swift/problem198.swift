//nearly the same as problem746
class Solution {
    func rob(_ nums: [Int]) -> Int {
        var max1 = 0; var max2 = 0; var cur = 0
        
        for cash in nums {
            cur = max(cash+max2,max1)
            max2 = max1
            max1 = cur
        }
        
        return max(max1,max2)
    }
}
