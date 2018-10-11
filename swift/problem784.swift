import Foundation
import Dispatch

//transplanted from https://leetcode.com/problems/letter-case-permutation/discuss/176493/C++-no-dfs-no-dp-O(1)-space-4ms-beats-100
//using dynamic array and Unicode.Scalar type
class Solution1 {
    func letterCasePermutation(_ S: String) -> [String] {
        let S = S.unicodeScalars
        var results = [""]
        let letters = CharacterSet.letters
        let uppers = CharacterSet.uppercaseLetters
        var isLetter = 0
        
        for char in S {
            let length = results.count
            if (letters.contains(char)) {
                if (uppers.contains(char)) {
                    isLetter = 1
                } else {
                    isLetter = -1
                }
            } else {
                isLetter = 0
            }
            
            if (isLetter != 0) {
                for index in 0..<length {
                    results.append(results[index]+(isLetter == 1 ? String(char).lowercased() : String(char).uppercased()))
                }
            }
            for index in 0..<length {
                results[index].append(Character((char)))
            }
        }
        return results
    }
}

//using dynamic array and Character type
class Solution2 {
    func letterCasePermutation(_ S: String) -> [String] {
        let S = Array(S.uppercased())
        let digits: Set<Character> = ["0","1","2","3","4","5","6","7","8","9"]
        var results = [""]
        
        for char in S {
            if digits.contains(char) {
                for var result in results {
                    result.append(char)
                }
            } else {
                for index in 0..<results.count {
                    results.append(results[index] + String(char).lowercased())
                    results[index].append(char)
                }
            }
        }
        return results
    }
}

//using pre-allocated array and Unicode.Scalar type
//no type conversion
class Solution3 {
    func letterCasePermutation(_ S: String) -> [[Unicode.Scalar]] {
        let S = Array(S.uppercased().unicodeScalars)
        let letters = CharacterSet.uppercaseLetters
        let result_size = 1 << S.filter{letters.contains($0)}.count
        var results = Array(repeating: S, count: result_size)
        var step = 1
        
        for i in 0..<S.count {
            if (letters.contains(S[i])) {
                let lower = Unicode.Scalar(S[i].value + 32)! //convert S[i] to lowercase
                for j in stride(from:0, to: result_size, by: step*2) {
                    for k in j..<(step+j) {
                        results[k][i] = lower
                    }
                }
                step *= 2
            }
        }
        return results
    }
}

//using pre-allocated array and Character type
//no type conversion
class Solution4 {
    func letterCasePermutation(_ S: String) -> [[Character]] {
        let S = Array(S.uppercased())
        let digits: Set<Character> = ["0","1","2","3","4","5","6","7","8","9"]
        let result_size = 1 << S.filter{!digits.contains($0)}.count
        var results = Array(repeating: S, count: result_size)
        var step = 1
        
        for i in 0..<S.count {
            if (!digits.contains(S[i])) {
                let lower = Character(String(S[i]).lowercased())
                for j in stride(from:0, to: result_size, by: step*2) {
                    for k in j..<(step+j) {
                        results[k][i] = lower
                    }
                }
                step *= 2
            }
        }
        return results
    }
}

//using pre-allocated array and Unicode.Scalar type
//converting [[Unicode.Scalar]] to [String]
class Solution5 {
    func letterCasePermutation(_ S: String) -> [String] {
        let S = Array(S.uppercased().unicodeScalars)
        let letters = CharacterSet.uppercaseLetters
        let result_size = 1 << S.filter{letters.contains($0)}.count
        var results = Array(repeating: S, count: result_size)
        var step = 1
        
        for i in 0..<S.count {
            if (letters.contains(S[i])) {
                let lower = Unicode.Scalar(S[i].value + 32)!
                for j in stride(from:0, to: result_size, by: step*2) {
                    for k in j..<(step+j) {
                        results[k][i] = lower
                    }
                }
                step *= 2
            }
        }
        return [String](results.compactMap{String($0.compactMap{Character($0)})})
    }
}

//using pre-allocated array and Character type
//converting [[Character]] to [String]
class Solution6 {
    func letterCasePermutation(_ S: String) -> [String] {
        let S = Array(S.uppercased())
        let digits: Set<Character> = ["0","1","2","3","4","5","6","7","8","9"]
        let result_size = 1 << S.filter{!digits.contains($0)}.count
        var results = Array(repeating: S, count: result_size)
        var step = 1
        
        for i in 0..<S.count {
            if (!digits.contains(S[i])) {
                let lower = Character(String(S[i]).lowercased())
                for j in stride(from:0, to: result_size, by: step*2) {
                    for k in j..<(step+j) {
                        results[k][i] = lower
                    }
                }
                step *= 2
            }
        }
        return [String](results.compactMap{String($0)})
    }
}

protocol sol {
    func letterCasePermutation(_ S: String) -> [String]
}
extension Solution1: sol{}
extension Solution2: sol{}
extension Solution5: sol{}
extension Solution6: sol{}

func time_consuming<T: sol>(_ solution_class: T, _ name: String, _ r: Int) {
    let time_start = DispatchTime.now().uptimeNanoseconds
    for _ in 1...r {
        _ = solution_class.letterCasePermutation("sjfdiewCf2bfewwgiHwGNO")
    }
    let time_end = DispatchTime.now().uptimeNanoseconds
    print(name,(time_end-time_start)/1000000,"ms","for \(r) times")
}

//1
time_consuming(Solution1(),"dynamics 1",5)

//2
time_consuming(Solution2(),"dynamics 2",5)

//3
var time_start = DispatchTime.now().uptimeNanoseconds
for _ in 1...5 {
    _ = Solution3().letterCasePermutation("sjfdiewCf2bfewwgiHwGNO")
}
var time_end = DispatchTime.now().uptimeNanoseconds
print("fixed, [[Unicode.Scalar]]",(time_end-time_start)/1000000,"ms","for 5 times")

//4
time_start = DispatchTime.now().uptimeNanoseconds
for _ in 1...5 {
    _ = Solution4().letterCasePermutation("sjfdiewCf2bfewwgiHwGNO")
}
time_end = DispatchTime.now().uptimeNanoseconds
print("fixed, [[Character]]",(time_end-time_start)/1000000,"ms","for 5 times")

//5
time_consuming(Solution5(),"[[US]] to [S]",5)

//6
time_consuming(Solution6(),"[[C]] to [S]",5)
/**
 swiftc -O problem784.swift && ./problem784
 
 test results
 
 dynamics 1 6902 ms for 5 times
 dynamics 2 7061 ms for 5 times
 fixed, [[Unicode.Scalar]] 6758 ms for 5 times
 fixed, [[Character]] 14863 ms for 5 times
 [[US]] to [S] 64430 ms for 5 times
 [[C]] to [S] 52077 ms for 5 times
 
 pre-allocated solution is slightly faster than dynamic solution;
 Unicode.Scalar is faster than Character;
 convertion from [[US]] or [[C]] to [S] is extremely slow
 **/
