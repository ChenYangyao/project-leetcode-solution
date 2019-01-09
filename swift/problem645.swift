class Solution1 {
    func findErrorNums(_ nums: [Int]) -> [Int] {
        let length = nums.count
        var check = Set<Int>()
        var error = 0; var sum = 0
        var checkError = true
        
        for number in nums {
            if checkError {
                if check.contains(number) {
                error = number
                checkError = false
                } else {
                    check.insert(number)
                }
            }
            sum += number
        }
        
        return [error,(1+length)*length/2-sum+error]
    }
}

// suppose the missing element is j and the duplicate one is k, then we have
//(1^2^3^...^n)^(^nums[i]) = j^k
class Solution2 {
    func findErrorNums(_ nums: [Int]) -> [Int] {
        var nums = nums; let length = nums.count
        var error = 0; var index = 0
        let tmp = [Int](1...length).reduce(0,^)^nums.reduce(0,^)
        
        for number in nums {
            if (number > 0) {
                index = number - 1
            } else {
                index = -number - 1
            }
            if (nums[index] > 0) {
                nums[index] = -nums[index]
            } else {
                error = index + 1
                break
            }
        }
        
        return [error, tmp^error]
    }
}
