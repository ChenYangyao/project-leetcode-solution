//core algorithm for problem653
class Solution {
    func twoSum(_ numbers: [Int], _ target: Int) -> [Int] {
        var head = 0
        var tail = numbers.count - 1
        var tmp = 0
        
        while true {
            tmp = numbers[head] + numbers[tail]
            if (tmp > target) {
                tail -= 1
            } else if (tmp < target) {
                head += 1
            } else {
                return [head + 1,tail + 1]
            }
        }
        
        return [0,0]
    }
}
