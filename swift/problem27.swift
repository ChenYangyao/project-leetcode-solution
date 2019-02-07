class Solution1 {
    func removeElement(_ nums: inout [Int], _ val: Int) -> Int {
        var counter = 0; let length = nums.count
        
        //we don't delete elements equal to val in situ, since remove(at: ) has time complexity O(N)
        for i in 0..<length {
            if (nums[i] == val) {
                nums.swapAt(i,counter)
                counter += 1
            }
        }
        
        nums.removeFirst(counter)
        return (length - counter)
    }
}

//ref: https://leetcode.com/problems/remove-element/solution/
class Solution2 {
    func removeElement(_ nums: inout [Int], _ val: Int) -> Int {
        var i = 0; var length = nums.count
        
        while (i < length) {
            if (nums[i] == val) {
                nums[i] = nums[length - 1]
                length -= 1
            } else {
                i += 1
            }
        }
        
        return length
    }
}
