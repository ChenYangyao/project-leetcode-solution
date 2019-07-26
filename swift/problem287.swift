class Solution {
    func findDuplicate(_ nums: [Int]) -> Int {
        var p1 = 0, p2 = 0
        
        repeat {
            p1 = nums[p1]
            p2 = nums[nums[p2]]
        } while (p1 != p2)
        
        p1 = 0
        while (p1 != p2) {
            p1 = nums[p1]
            p2 = nums[p2]
        }
        
        return p1
    }
}
