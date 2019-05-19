class Solution {
    func minMoves2(_ nums: [Int]) -> Int {
        var nums = nums.sorted()
        var head = 0
        var tail = nums.count - 1
        var ans = 0
        
        while (head < tail) {
            let tmp = nums[tail] - nums[head]
            if (tmp == 0) {
                break
            } else {
                ans += tmp
            }
            head += 1
            tail -= 1
        }
        
        return ans
    }
}
