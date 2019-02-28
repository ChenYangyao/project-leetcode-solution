class Solution {
    func thirdMax(_ nums: [Int]) -> Int {
        var first = nums[0]; var second: Int?; var third: Int?
        
        for number in nums {
            if (number > first) {
                if (second != nil) {
                    third = second
                }
                second = first
                first = number
            } else if (number == first) {
                continue
            } else if (number > second ?? Int.min) {
                if (second != nil) {
                    third = second
                }
                second = number
            } else if (number == second) {
                continue
            } else if (number > third ?? Int.min){
                third = number
            }
        }
        
        return third ?? first
    }
}
