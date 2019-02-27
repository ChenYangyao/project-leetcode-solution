class Solution1 {
    func findUnsortedSubarray(_ nums: [Int]) -> Int {
        let numsSorted = nums.sorted()
        
        var head = 0; var tail = nums.count - 1
        
        while (nums[head] == numsSorted[head]) {
            if (head == tail) {
                return 0
            }
            head += 1
        }
        
        while (nums[tail] == numsSorted[tail]) {
            tail -= 1
        }
        
        return tail - head + 1
    }
}

//sample Sln
//same thought as Approach 5
//https://leetcode.com/problems/shortest-unsorted-continuous-subarray/solution/
class Solution2 {
    func findUnsortedSubarray(_ nums: [Int]) -> Int {
        var start = -1; var end = -2
        var maxN = Int.min; var minN = Int.max
        var p1 = 0; var p2 = nums.count-1

        for _ in 0..<nums.count {
            if (nums[p1] < maxN) {
                end = p1
            }
            maxN = max(nums[p1], maxN)
            p1 += 1
        }

        for _ in 0..<nums.count {
            if (nums[p2] > minN) {
                start = p2
            }
            minN = min(nums[p2], minN)
            p2 -= 1
        }
        return end-start+1
    }
}
