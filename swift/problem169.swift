class Solution1 {
    func majorityElement(_ nums: [Int]) -> Int {
        var counter = [Int:Int]()
        var half = nums.count / 2
        for number in nums {
            counter[number, default: 0] += 1
        }
        
        for (key, value) in counter {
            if (value > half) {
                return key
            }
        }
        return 0
    }
}

//the key point for solution2 is that the majority number accounts for more than half of the array so that it is guaranteed the majority number can be assigned to "key" during the for-loop
class Solution2 {
    func majorityElement(_ nums: [Int]) -> Int {
        var key = 0
        var time = 0
        var index = nums.count
        
        while (index > time) {
            index -= 1
            if (time != 0) {
                time += (key == nums[index]) ? 1 : -1
            } else {
                key = nums[index]
                time = 1
            }
        }
        return key
    }
}
