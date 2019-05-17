class Solution {
    func arrayNesting(_ nums: [Int]) -> Int {
        let length = nums.count; var idx = 0
        
        var visited = Set<Int>(); var ans = 0; var tmp = 0
        
        while (idx < length) {
            let next = nums[idx]
            if !visited.contains(next) {
                visited.insert(next)
                tmp += 1
                idx = next
            } else {
                idx += 1
                ans = max(ans, tmp)
                tmp = 0
            }
        }
        
        return ans
    }
}
