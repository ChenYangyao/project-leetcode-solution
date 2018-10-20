import Dispatch

//directly calculate the answer. time complexity O(n) where n = sig. dig. of N
class Solution1 {
    private let lesser = [0,4,40,316,2320] //the quantity of good numbers with 0,1,2,3,4 sig. dig.
    private let bad_d = Set([3,4,7]) //if a number contains digits in bad_d, then it is invalid
    private let good_d = Set([2,5,6,9]) //if a digit is in good_d, its following digits can be any valid ones
    
    private func good(_ digit: Int) -> Int { //return the quantity of good digits lesser than "digit"
        switch digit {
        case 7...9:
            return 3
        case 6:
            return 2
        case 3...5:
            return 1
        default:
            return 0
        }
    }
    
    private func mediocre(_ digit: Int) -> Int { //return the quantity of mediocre digits (0,1,8) lesser than "digit"
        switch digit {
        case 9:
            return 3
        case 2...8:
            return 2
        case 1:
            return 1
        default:
            return 0
        }
    }
    
    private func valid(_ digit: Int) -> Int { //return the quantity of valid digits lesser than "digit"
        switch digit {
        case 9:
            return 6
        case 7...8:
            return 5
        case 6:
            return 4
        case 3...5:
            return 3
        case 2:
            return 2
        case 1:
            return 1
        default:
            return 0
        }
    }
    
    private func residue_good(_ digit: Int) -> Int { //return the quantity of good digits lesser eq. to "digit"
        switch digit {
        case 9:
            return 7
        case 8:
            return 6
        case 6...7:
            return 5
        case 5:
            return 4
        case 2...4:
            return 3
        case 1:
            return 2
        default:
            return 1
        }
    }
    
    private func residue_normal(_ digit: Int) -> Int { //return the quantity of valid digits lesser eq. to "digit"
        switch digit {
        case 9:
            return 4
        case 6...8:
            return 3
        case 5:
            return 2
        case 2...4:
            return 1
        default:
            return 0
        }
    }
    
    private func pow(_ power: Int) -> Int { //return 7^power
        var result = 1
        for _ in 0..<power {
            result *= 7
        }
        return result
    }
    
    func rotatedDigits(_ N: Int) -> Int {
        var N = N
        
        if (N < 10) {
            return residue_normal(N)
        }
        
        var digits = [Int]()
        
        while (N > 0) {
            digits.append(N%10)
            N /= 10
        }
        //convert N into array
        
        let length = digits.count - 1
        var result = 0
        var flag_bad = false //to record whether bad digits have been visited
        var flag_good = false //to record whether good digits have been visited
        
        for index in (1...length).reversed() { //last digit needs to be treated separately
            let digit = digits[index]
            if (digit != 0) {
                if (flag_good && !flag_bad) {
                    result += valid(digit)*pow(index)
                } else if (!flag_good && !flag_bad) {
                    result += (good(digit)*pow(index) + mediocre(digit)*lesser[index])
                } else {
                    break
                }
                flag_bad = bad_d.contains(digit)
                flag_good = flag_good || good_d.contains(digit)
            }
        }
        
        if flag_bad {
            return result
        }
        if flag_good {
            return (result + residue_good(digits[0]))
        }
        return (result + residue_normal(digits[0]))
    }
}

//using array instead of function
class Solution2 {
    private let lesser = [0,4,40,316,2320]
    private let bad_d = Set([3,4,7])
    private let good_d = Set([2,5,6,9])
    private let good = [0,0,0,1,1,1,2,3,3,3]
    private let mediocre = [0,1,2,2,2,2,2,2,2,3]
    private let valid = [0,1,2,3,3,3,4,5,5,6]
    private let residue_good = [1,2,3,3,3,4,5,5,6,7]
    private let residue_normal = [0,0,1,1,1,2,3,3,3,4]
    
    private func pow(_ power: Int) -> Int {
        var result = 1
        for _ in 0..<power {
            result *= 7
        }
        return result
    }
    
    func rotatedDigits(_ N: Int) -> Int {
        var N = N
        
        if (N < 10) {
            return residue_normal[N]
        }
        
        var digits = [Int]()
        
        while (N > 0) {
            digits.append(N%10)
            N /= 10
        }
        
        let length = digits.count - 1
        var result = 0
        var flag_bad = false
        var flag_good = false
        
        for index in (1...length).reversed() {
            let digit = digits[index]
            if (digit != 0) {
                if (flag_good && !flag_bad) {
                    result += valid[digit]*pow(index)
                    
                } else if (!flag_good && !flag_bad) {
                    result += (good[digit]*pow(index) + mediocre[digit]*lesser[index])
                } else {
                    break
                }
                flag_bad = bad_d.contains(digit)
                flag_good = flag_good || good_d.contains(digit)
            }
        }
        
        if flag_bad {
            return result
        }
        if flag_good {
            return (result + residue_good[digits[0]])
        }
        return (result + residue_normal[digits[0]])
    }
}

protocol sol {
    func rotatedDigits(_ N: Int) -> Int
}
extension Solution1: sol{}
extension Solution2: sol{}

func time_consuming<T: sol>(_ solution_class: T, _ name: String, _ r: Int) {
    let time_start = DispatchTime.now().uptimeNanoseconds
    for _ in 1...r {
        _ = solution_class.rotatedDigits(98765)
    }
    let time_end = DispatchTime.now().uptimeNanoseconds
    print(name,(time_end-time_start)/1000000,"ms","for \(r) times")
}

time_consuming(Solution1(),"func",10000000)
time_consuming(Solution2(),"arr.",10000000)

//no significant performance difference.
