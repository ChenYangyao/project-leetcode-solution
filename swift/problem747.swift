class Solution {
    func dominantIndex(_ nums: [Int]) -> Int {
        var largestIndex = 0; var largest = 0; var secondLargest = 0
        
        for i in 0..<nums.count {
            let tmp = nums[i]
            if (tmp > secondLargest) {
                if (tmp > largest) {
                    secondLargest = largest
                    largest = tmp
                    largestIndex = i
                } else {
                    secondLargest = tmp
                }
            }
        }
        
        return largest >= secondLargest*2 ? largestIndex : -1
    }
}
