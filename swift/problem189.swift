//ref: https://leetcode.com/problems/rotate-array/solution/
//Approach 3
class Solution {
    func rotate(_ nums: inout [Int], _ k: Int) {
        let length = nums.count
        let k = k%length
        
        var start = 0; var counter = 0
        
        while (counter < length) {
            var current = start
            var prev = nums[start]
            repeat {
                let next = (current+k)%length
                let tmp = nums[next]
                nums[next] = prev
                prev = tmp
                current = next
                counter += 1
            } while (start != current)
            start += 1
        }
    }
}
