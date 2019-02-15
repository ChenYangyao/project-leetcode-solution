import Dispatch

//this solution is similar to Approach #1: Group By Character. since we don't need all information stored in groups[] but only the top two elements of it, we use two Int variables length_1 & length_2 instead.

//since string s only contains 1 or 0, we convert it into Bool array to reduce the space usage and speed up comparison between s[index] and flag.
class Solution1 {
    private var last_index = 0
    private var s_bool = [Bool]()
    
    func countBinarySubstrings(_ s: String) -> Int {
        s_bool = s.compactMap{$0 == "1" ? true : false} //this conversion is time consuming.
        last_index = s_bool.count
        var index = 0
        var length_1 = moveIndex(&index)
        var length_2 = 0
        var result = 0
        
        while (index < last_index) {
            length_2 = moveIndex(&index)
            result += min(length_1, length_2)
            length_1 = length_2
        }
        return result
    }
    
    private func moveIndex(_ index: inout Int) -> Int {
        let flag = s_bool[index]
        var count = 0
        for i in index..<last_index {
            if (s_bool[i] == flag) {
                count += 1
            } else {
                break
            }
        }
        index += count
        return count
    }
}

//convert string into character array
class Solution2 {
    private var last_index = 0
    private var s_array = [Character]()
    
    func countBinarySubstrings(_ s: String) -> Int {
        s_array = Array(s) //this conversion is time consuming.
        last_index = s_array.count
        var index = 0
        var length_1 = moveIndex(&index)
        var length_2 = 0
        var result = 0
        
        while (index < last_index) {
            length_2 = moveIndex(&index)
            result += min(length_1, length_2)
            length_1 = length_2
        }
        return result
    }
    
    private func moveIndex(_ index: inout Int) -> Int {
        let flag = s_array[index]
        var count = 0
        for i in index..<last_index {
            if (s_array[i] == flag) { //slower than Solution1
                count += 1
            } else {
                break
            }
        }
        index += count
        return count
    }
}

//visit characters in string directly using String.Index
//slowest solution. may due to s.indices[]?
class Solution3 {
    func countBinarySubstrings(_ s: String) -> Int {
        var s = s
        var last_index = s.endIndex
        var index = s.startIndex
        var length_1 = moveIndex(&s,&index,&last_index)
        var length_2 = 0
        var result = 0
        
        while (index < last_index) {
            length_2 = moveIndex(&s,&index,&last_index)
            result += min(length_1, length_2)
            length_1 = length_2
        }
        return result
    }
    
    private func moveIndex(_ s: inout String, _ index: inout String.Index, _ last_index: inout String.Index) -> Int {
        let flag = s[index]
        var count = 0
        for i in s.indices[index..<last_index] {
            if (s[i] == flag) {
                count += 1
            } else {
                break
            }
        }
        s.formIndex(&index, offsetBy: count)
        return count
    }
}

//ref: sample 68 ms submission. Algorithm: Approach #2 Linear Scan
class Solution4 {
    func countBinarySubstrings(_ s: String) -> Int {
        
        var prevRunLength = 0
        var curRunLength = 1
        var res = 0
        var arr = s.compactMap{$0 == "1" ? true : false}
        
        for i in 1..<arr.count {
            if arr[i] == arr[i - 1] { //since every elements except front and rear ones are visited twice, this solution should be slower than ours
                curRunLength += 1
            } else {
                prevRunLength = curRunLength
                curRunLength = 1
            }
            if prevRunLength >= curRunLength {
                res+=1
            }
        }
        return res
    }
}

protocol sol {
    func countBinarySubstrings(_ s: String) -> Int
}
extension Solution1: sol{}
extension Solution2: sol{}
extension Solution3: sol{}
extension Solution4: sol{}

func time_consuming<T: sol>(_ solution_class: T, _ name: String, _ r: Int) {
    let time_start = DispatchTime.now().uptimeNanoseconds
    for _ in 1...r {
        _ = solution_class.countBinarySubstrings(test)
    }
    let time_end = DispatchTime.now().uptimeNanoseconds
    print(name,(time_end-time_start)/1000000,"ms","for \(r) times")
}

var test = String()

for _ in 0..<1000000 {
    test.append(String(Int.random(in: 0...1)))
}

let r = 500
time_consuming(Solution1(),"Bool Array",r)
time_consuming(Solution2(),"Char Array",r)
time_consuming(Solution3(),"String",r)
time_consuming(Solution4(),"Ref",r)
/**
 test result for s.count = 1000000:
 Bool Array 21373 ms for 500 times
 Char Array 37829 ms for 500 times
 String 64660 ms for 500 times
 Ref 21497 ms for 500 times
 **/
