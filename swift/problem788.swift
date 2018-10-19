//directly calculate the answer. time complexity O(n) where n = sig. dig. of N
class Solution {
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
        if (power == 0) {
            return 1
        }
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
        var result = lesser[length] //quantity of good numbers with (length-1) sig. dig.
        var flag_bad = bad_d.contains(digits[length]) //to record whether bad digits have been visited
        var flag_good = good_d.contains(digits[length]) //to record whether good digits have been visited
        
        for index in (1...length).reversed() { //last digit needs to be treated separately
            let digit = digits[index]
            if (index == length) {
                if (digit != 1) {
                    result += (good(digit)*pow(index) + (mediocre(digit)-1)*lesser[index]) //-1 because digit = 0 has been included in lesser[length]
                }
            } else if (digit != 0) {
                if (flag_good && !flag_bad) {
                    result += valid(digit)*pow(index)
                    flag_bad = flag_bad || bad_d.contains(digit)
                    flag_good = flag_good || good_d.contains(digit)
                } else if (!flag_good && !flag_bad) {
                    result += (good(digit)*pow(index) + mediocre(digit)*lesser[index])
                    flag_bad = flag_bad || bad_d.contains(digit)
                    flag_good = flag_good || good_d.contains(digit)
                } else {
                    break
                }
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
