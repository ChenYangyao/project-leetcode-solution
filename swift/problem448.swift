import Dispatch

//for any number in the array nums, turning the number-th element into negative one. For numbers dissapear in the array, the elements on their positions will be positive.
class Solution1 {
    func findDisappearedNumbers(_ nums: [Int]) -> [Int] {
        var nums = nums
        var dis = [Int]()
        var index = 0
        
        for number in nums {
            if (number > 0) { //slightly faster than abs()
                index = number - 1
            } else {
                index = -number - 1
            }
            if (nums[index] > 0) {
                nums[index] = -nums[index]
            }
        }
        
        for index in 0..<nums.count {
            if (nums[index] > 0) {
                dis.append(index + 1)
            }
        }
        
        return dis
    }
}

//not O(n). ref: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/discuss/178735/c++-simple-o(n)-solution
class Solution2 {
    func findDisappearedNumbers(_ nums: [Int]) -> [Int] {
        var nums = nums
        var dis = [Int]()
        let length = nums.count
        
        for i in 0..<length {
            while (nums[i] != i + 1) {
                let index = nums[i] - 1
                if (nums[i] == nums[index]) { //prevent infinite loop due to duplicate numbers in nums
                    break
                }
                nums.swapAt(i,index)
            }
        }
        
        for i in 0..<length {
            if (nums[i] != (i+1)) {
                dis.append(i+1)
            }
        }
        return dis
    }
}

protocol sol {
    func findDisappearedNumbers(_ nums: [Int]) -> [Int]
}
extension Solution1: sol{}
extension Solution2: sol{}

func time_consuming<T: sol>(_ solution_class: T, _ name: String, _ r: Int) {
    let time_start = DispatchTime.now().uptimeNanoseconds
    for _ in 1...r {
        _ = solution_class.findDisappearedNumbers(test)
    }
    let time_end = DispatchTime.now().uptimeNanoseconds
    print(name,(time_end-time_start)/1000000,"ms","for \(r) times")
}

var test = [Int]()

for _ in 0..<100000 {
    test.append(Int.random(in: 1...100000))
}

time_consuming(Solution1(),"1",10000)
time_consuming(Solution2(),"2",10000)
