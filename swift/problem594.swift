import Dispatch

class Solution1 {
    func findLHS(_ nums: [Int]) -> Int {
        var times = nums.reduce(into: [:]){$0[$1,default: 0] += 1}
        var ans = 0
        
        for (number,time) in times {
            guard let tmp = times[number+1] else {
                continue
            }
            ans = max(ans,time + tmp)
        }
        
        return ans
    }
}

//ref: https://leetcode.com/problems/longest-harmonious-subsequence/solution/
class Solution2 {
    func findLHS(_ nums: [Int]) -> Int {
        var times = [Int:Int]()
        var ans = 0
        
        for number in nums {
            times[number,default: 0] += 1
            if let tmp1 = times[number+1] {
                ans = max(ans,times[number]!+tmp1)
            }
            if let tmp2 = times[number-1] {
                ans = max(ans,times[number]!+tmp2)
            }
        }
        
        return ans
    }
}

protocol sol {
    func findLHS(_ nums: [Int]) -> Int
}
extension Solution1: sol{}
extension Solution2: sol{}

func time_consuming<T: sol>(_ solution_class: T, _ name: String, _ input: [Int], _ r: Int) {
    let time_start = DispatchTime.now().uptimeNanoseconds
    for _ in 1...r {
        _ = solution_class.findLHS(input)
    }
    let time_end = DispatchTime.now().uptimeNanoseconds
    print(name,(time_end-time_start)/1000000,"ms","for \(r) times")
}

var input1 = [Int](repeating: 0, count: 20_000)
var input2 = [Int](repeating: 0, count: 20_000)
for i in 0..<20_000 {
    input1[i] = Int.random(in: 1...10_000)
}
for i in 0..<20_000 {
    input2[i] = Int.random(in: 1...10)
}

time_consuming(Solution1(),"double traversal, large dict",input1,1000)
time_consuming(Solution2(),"single traversal, large dict",input1,1000)
time_consuming(Solution1(),"double traversal, small dict",input2,1000)
time_consuming(Solution2(),"single traversal, small dict",input2,1000)

/*
 double traversal, large dict 2312 ms for 1000 times
 single traversal, large dict 4249 ms for 1000 times
 double traversal, small dict 838 ms for 1000 times
 single traversal, small dict 2991 ms for 1000 times
 
 Although Solution2 only traverses once over array nums, it needs to compare twice for
 each element of nums. When nums contains only a few different numbers, Solution1 with
 pre-generate dictionary is much more efficient than Solution2.
*/
